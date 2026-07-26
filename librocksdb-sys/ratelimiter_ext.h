#pragma once

#include "rocksdb/c.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dynamically adjusts the limiter's rate; wraps the thread-safe
   RateLimiter::SetBytesPerSecond, which the RocksDB C API does not expose. */
extern ROCKSDB_LIBRARY_API void rocksdb_ratelimiter_set_bytes_per_second(
    rocksdb_ratelimiter_t* limiter, int64_t rate_bytes_per_sec);

#ifdef __cplusplus
}
#endif
