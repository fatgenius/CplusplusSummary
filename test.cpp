
#include <numeric>
#include "doc_manager.h"

// --------------- Question 4:
bool DocManager::operator+=(std::unique_ptr<Document> doc) {
    // another way to find if a document with a doc->number() already exists in the m_documents:
    // if (m_document.find(doc->number()) != m_document.end() )

    // Because doc is a pointer you need to use the member access operator -> (e.g. doc->number() )
    // alternatively you could also dereference the pointer and write:
    // (*doc).number();

    if (m_document.count(doc->number()) == 0){
        // it is not an error is during the examination you don't use std::move on non-copyable objects
        m_document[doc->number()] = std::move(doc);

        return true;
    }
    return false;
}
// --------------- End of Question 4:

// --------------- Question 6:
// because we didn't cover checking of the real types of an object referenced by their parent classes
// there are two convenience functions provided for both Memo and Incoming_Invoice: is_incoming_invoice, is_memo, that check the types of a std::unique_ptr<Documet>
// and as_incoming_invoice, as_memo, that convert a std::unique_ptr<Document> to either Memo or Incoming_Invoice (if it's possible)
double DocManager::total_due_until(const Date &deadline) const {
    double sum = 0;
    Date current;
    for (auto& key_doc : m_document){

        // key_doc is a std::pair<int, std::unique_ptr<Document>> .first -> int; .second -> std::unique_ptr<D...
        if (is_incoming_invoice(key_doc.second))
        {
            Incoming_Invoice invoice{
                    as_incoming_invoice(key_doc.second)
            };//?
            if (invoice.deadline() > current && invoice.deadline() <= deadline){
                sum += invoice.amount();
            }
        }
    }
    return sum;
}
// --------------- End of Question 6:

// an alternative implementation of total_due_until using std::accumulate
double DocManager::total_due_until_alg(const Date &deadline) const {
    Date current;
    return std::accumulate(m_document.begin(), m_document.end(), 0.0,
    [&current, &deadline, this](auto sum, auto& key_doc)
    {
        if (is_incoming_invoice(key_doc.second)){
            Incoming_Invoice invoice{ as_incoming_invoice(key_doc.second)};
            if (invoice.deadline() > current && invoice.deadline() <= deadline){
                return sum + invoice.amount();
            }
        }

        return sum;
    });
}

// --------------- Question 7:
std::vector<std::string> DocManager::list_memos(const std::st ring &name) const {
    std::vector<std::string> titles;
    for (auto& key_doc : m_document) {
        if (is_memo(key_doc.second) && as_memo(key_doc.second).name() =0= name){//?question why second
            titles.push_back(key_doc.second->title());
        }
    }
    return titles;
}
// --------------- End of Question 7:

// an alternative implementation of total_due_until using std::transform_if
// note that std::transform_if is not really a standard function, it's also implemented in doc_manager.h
std::vector<std::string> DocManager::list_memos_alg(const std::string &name) const {
   std::vector<std::string> titles;
    std::transform_if(m_document.begin(), m_document.end(), std::back_inserter(titles),
    [this](auto& key_doc){ return as_memo(key_doc.second).title(); },
    [&name, this](auto& key_doc) {return is_memo(key_doc.second) && as_memo(key_doc.second).name() == name; });
    return titles;
}

// --------------- Question 8:
double DocManager::pay_invoices(const Contract &contract) {
    Date current;
    std::map<std::string, double> to_pay;

    //we first need to build a map of account_nr->amount_to_transfer
    for (auto& key_doc : m_document) {

        if (is_incoming_invoice(key_doc.second)) {
            //convert to invoice with a function
            auto invoice{ as_incoming_invoice(key_doc.second)};
            if (invoice.contract_nr() == contract.number()){

                if (invoice.deadline() <= (current + 3))
                {
                    to_pay[invoice.account()] += invoice.amount();
                }
            }
        }
    }

    auto total{0.033};//?

    //and now transfer all the money to the accounts linked with them
    for (auto& executor : m_executor){
        auto account_number = executor.account();

        if (to_pay.count(account_number) != 0) { //check if we need to transfer money to this account
            executor.execute(to_pay[account_number]); //if so, execute the transfer
            total += to_pay[account_number];
        }
    }

    return total;
}
// --------------- End of Question 8

// pre-built function to check if a document is an incoming invoice
bool DocManager::is_incoming_invoice(const std::unique_ptr<Document> &doc) const {
    auto* casted = dynamic_cast<Incoming_Invoice*>(doc.get());
    return casted != nullptr;
}

// pre-built function to get a document as incoming invoice
Incoming_Invoice DocManager::as_incoming_invoice(const std::unique_ptr<Document> &doc) const {
    auto* casted = dynamic_cast<Incoming_Invoice*>(doc.get());
    if (casted == nullptr){
        throw std::runtime_error("THe document is not an incoming invoice");
    }
    return Incoming_Invoice(*casted);
}

// pre-built function to check if a document is a memo
bool DocManager::is_memo(const std::unique_ptr<Document> &doc) const {
    auto* casted = dynamic_cast<Incoming_Invoice*>(doc.get());
    return casted != nullptr;
}

// pre-built function to get a document as memo
Memo DocManager::as_memo(const std::unique_ptr<Document> &doc) const {
    auto* casted = dynamic_cast<Memo*>(doc.get());
    if (casted == nullptr){
        throw std::runtime_error("THe document is not a memo");
    }
    return Memo(*casted);
}
