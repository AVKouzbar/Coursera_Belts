#include "node.h"

template <class T>
bool Compare(Comparison cmp, const T& a, const T& b) {
    switch (cmp)
    {
        case Comparison ::Less:
            return a < b;

        case Comparison ::LessOrEqual:
            return a <= b;

        case Comparison ::Greater:
            return a > b;

        case Comparison ::GreaterOrEqual:
            return a >= b;

        case Comparison ::Equal:
            return a == b;

        case Comparison ::NotEqual:
            return a != b;
    }

    throw invalid_argument("Invalid comparison operator ");
}



bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(cmp_, date, date_ );
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(cmp_, event, event_);
}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    (void) date; (void) event;

    switch(op_){
        case LogicalOperation ::Or:
            return lhs_->Evaluate(date, event) || rhs_->Evaluate(date,event);
        case LogicalOperation ::And:
            return lhs_->Evaluate(date, event) && rhs_->Evaluate(date,event);
    }
    throw invalid_argument("Invalid logical operation");
}