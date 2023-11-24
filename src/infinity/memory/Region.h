/*
 * Memory - Region
 *
 * (c) 2018 Claude Barthels, ETH Zurich
 * Contact: claudeb@inf.ethz.ch
 *
 */

#ifndef MEMORY_REGION_H_
#define MEMORY_REGION_H_

#include <stdint.h>
#include <infiniband/verbs.h>

#include <infinity/core/Context.h>
#include <infinity/memory/RegionType.h>

namespace infinity {
namespace memory {

class RegionToken;

class Region {

public:

	virtual ~Region();

    //为当前MR的整片内存区域创建Token
	RegionToken *createRegionToken();
    //为以当前MR地址偏移为offset，大小为sizeInBytes-offset的内存区域创建Token
	RegionToken *createRegionToken(uint64_t offset);
    //为以当前MR地址偏移为offset，大小为size的内存区域创建Token
	RegionToken *createRegionToken(uint64_t offset, uint64_t size);

public:

	RegionType getMemoryRegionType();
	uint64_t getSizeInBytes();
	uint64_t getRemainingSizeInBytes(uint64_t offset);
	uint64_t getAddress();
	uint64_t getAddressWithOffset(uint64_t offset);
	uint32_t getLocalKey();
	uint32_t getRemoteKey();

protected:

	infinity::core::Context *context;
	RegionType memoryRegionType;
	ibv_mr *ibvMemoryRegion;

protected:

	void *data;
	uint64_t sizeInBytes;

};

} /* namespace memory */
} /* namespace infinity */

#endif /* MEMORY_REGION_H_ */
