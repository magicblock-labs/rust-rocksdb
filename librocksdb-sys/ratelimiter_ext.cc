#include "ratelimiter_ext.h"

#include <cstdint>
#include <memory>

#include "rocksdb/rate_limiter.h"

using ROCKSDB_NAMESPACE::RateLimiter;

// Must mirror the definition in rocksdb/db/c.cc, which is private to that
// translation unit; the C API exposes no other way to reach the limiter.
struct rocksdb_ratelimiter_t {
  std::shared_ptr<RateLimiter> rep;
};

extern "C" void rocksdb_ratelimiter_set_bytes_per_second(
    rocksdb_ratelimiter_t* limiter, int64_t rate_bytes_per_sec) {
  // SetBytesPerSecond requires a positive rate (asserted in debug builds).
  if (rate_bytes_per_sec <= 0) {
    return;
  }
  limiter->rep->SetBytesPerSecond(rate_bytes_per_sec);
}
