cmake_minimum_required(VERSION 2.8.10)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

set(COMPAT_SRC
  compat/inet_ntop.c
  
  compat/inet_pton.c
  compat/ctime_r.c
  compat/strptime.c

  compat/getentropy_solaris.c
  compat/gmtime_r.c
  compat/getentropy_win.c
  compat/explicit_bzero.c
  compat/strsep.c
  compat/getentropy_osx.c
  compat/strlcat.c
  compat/reallocarray.c
  compat/sha512.c
  compat/arc4_lock.c
  compat/fake-rfc2553.c
  compat/isblank.c
  compat/inet_aton.c
  compat/strlcpy.c
  compat/snprintf.c

  compat/malloc.c
  compat/memmove.c
  compat/memcmp.c
)

set(ARC4RAND_SRC
    compat/arc4random.c
    compat/arc4random_uniform.c)

if(LINUX)
  set(ARC4RAND_SRC ${ARC4RAND_SRC}
    compat/getentropy_linux.c)
endif()

set(EXT)

set(LIBUNBOUND_SRC 
  sldns/parseutil.c
  sldns/keyraw.c
  sldns/rrdef.c
  sldns/parse.c
  sldns/sbuffer.c
  sldns/wire2str.c
  sldns/str2wire.c
  libunbound/context.c
  libunbound/libworker.c
  libunbound/libunbound.c
  daemon/unbound.c
  daemon/daemon.c
  daemon/acl_list.c
  daemon/worker.c
  daemon/remote.c
  daemon/cachedump.c
  daemon/stats.c
  ipsecmod/ipsecmod.c
  ipsecmod/ipsecmod-whitelist.c
  iterator/iterator.c
  iterator/iter_resptype.c
  iterator/iter_scrub.c
  iterator/iter_hints.c
  iterator/iter_utils.c
  iterator/iter_priv.c
  iterator/iter_delegpt.c
  iterator/iter_donotq.c
  iterator/iter_fwd.c
  dnscrypt/dnscrypt.c
  services/view.c
  services/authzone.c
  services/cache/rrset.c
  services/cache/infra.c
  services/cache/dns.c
  services/outside_network.c
  services/outbound_list.c
  services/localzone.c
  services/modstack.c
  services/mesh.c
  services/listen_dnsport.c
  util/ub_event_pluggable.c
  util/rbtree.c
  util/module.c
  util/netevent.c
  util/configparser.c
  util/as112.c
  util/ub_event.c
  util/data/msgparse.c
  util/data/dname.c
  util/data/packed_rrset.c
  util/data/msgencode.c
  util/data/msgreply.c
  util/timehist.c
  util/locks.c
  util/net_help.c
  util/configlexer.c
  util/rtt.c
  util/log.c
  util/alloc.c
  util/storage/slabhash.c
  util/storage/lruhash.c
  util/storage/dnstree.c
  util/storage/lookup3.c
  util/config_file.c
  util/mini_event.c
  util/random.c
  util/regional.c
  util/fptr_wlist.c
  util/winsock_event.c
  util/shm_side/shm_main.c
  util/tube.c
  respip/respip.c
  edns-subnet/edns-subnet.c
  edns-subnet/subnetmod.c
  edns-subnet/subnet-whitelist.c
  edns-subnet/addrtree.c
  cachedb/cachedb.c
  cachedb/redis.c
  dns64/dns64.c
  smallapp/unbound-anchor.c
  smallapp/unbound-control.c
  smallapp/unbound-host.c
  smallapp/worker_cb.c
  smallapp/unbound-checkconf.c
  validator/val_nsec3.c
  validator/val_nsec.c
  validator/autotrust.c
  validator/val_kcache.c
  validator/val_anchor.c
  validator/val_secalgo.c
  validator/val_kentry.c
  validator/validator.c
  validator/val_sigcrypt.c
  validator/val_utils.c
  validator/val_neg.c
  ${EXTRA_SRC}
)

add_library(unbound ${LIBUNBOUND_SRC})

if(SODIUM_INCLUDE_DIR)
  include_directories(${SODIUM_INCLUDE_DIR})
endif()

if(SODIUM_LIBRARIES)
  set(SODIUM_LIB ${SODIUM_LIBRARIES})
else()
  find_library (
          SODIUM_LIB
          NAMES sodium libsodium
          HINTS "/usr/local/lib"
  )
endif()

if(OPENSSL_INCLUDE_DIR AND OPENSSL_LIBRARIES)
  include_directories(${OPENSSL_INCLUDE_DIR})
  set(OPENSSL_LIB ${OPENSSL_LIBRARIES})
else()
  find_package(OpenSSL)
  if(OpenSSL_FOUND)
    set(OPENSSL_LIB ${OpenSSL_LIBRARY})
    include_directories(${OpenSSL_INCLUDE_DIR})
  else()
  message(FATAL libssl not found)
  endif()
endif()

set(LIBS ${SODIUM_LIB} ${OPENSSL_LIB})

target_link_libraries(unbound ${LIBS})
