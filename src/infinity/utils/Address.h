/**
 * Utils - Address
 *
 * (c) 2018 Claude Barthels, ETH Zurich
 * Contact: claudeb@inf.ethz.ch
 *
 */

#ifndef UTILS_ADDRESS_H_
#define UTILS_ADDRESS_H_

#include <stdint.h>

namespace infinity {
namespace utils {

class Address {

public:

    //以字符串方式获取ip地址
	static char *getIpAddressOfInterface(const char *interfaceName);
    //以32位无符号整数方式获取ip地址
	static uint32_t getIpAddressAsUint32(const char *ipAddress);

};

} /* namespace utils */
} /* namespace infinity */

#endif /* UTILS_ADDRESS_H_ */
