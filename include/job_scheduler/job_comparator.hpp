#include "job.hpp"
struct JobComparator
{
    bool operator()(const Job &lhs, const Job &rhs) const;
};
