#ifndef UPSTREAM_B__UPSTREAM_B_HPP_
#define UPSTREAM_B__UPSTREAM_B_HPP_

#include <string>

namespace upstream_b
{

/// "elements=N" for an XML document with N elements, "invalid" if it does not parse.
std::string summarize(const std::string & xml);

}  // namespace upstream_b

#endif  // UPSTREAM_B__UPSTREAM_B_HPP_
