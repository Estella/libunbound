#ifndef LIBUNBOUND_CONFIG_H
#define LIBUNBOUND_CONFIG_H


/**
   shim replacement for GNU/autobloat generated config.h
   TOOD: implement correctly
*/

#ifdef __linux__
#include <bsd/string.h>
#include <bsd/stdlib.h>
#include <linux/ipv6.h>
#define __USE_GNU
#endif

#define __USE_XOPEN
#define _XOPEN_SOURCE

#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/param.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>


#define HAVE_ENDIAN_H
#define HAVE_SYSLOG_H
#define HAVE_NETDB_H
#define HAS_STDINT_H
#define HAVE_PTHREAD
#define HAVE_SYS_WAIT_H
#define HAVE_TIME_H
#define ATTR_FORMAT(...)
#define ATTR_UNUSED(x) x

#define MAXSYSLOGMSGLEN (128)

#define CONFIGFILE "/etc/lokinet-unbound.ini"
#define PACKAGE_VERSION  "0.0.1"
#define PACKAGE_STRING "lokinet-unbound-"PACKAGE_VERSION
#define PACKAGE_BUGREPORT "https://github.com/loki-project/libunbound"

#define UB_USERNAME "unbound"
#define RUN_DIR "/var/run/unbound"
#define PIDFILE "/var/run/unbound.pid"

#define UNBOUND_DNS_PORT (53)
#define UNBOUND_CONTROL_PORT (8853)
#define UNBOUND_CONTROL_VERSION (10)
#define UNBOUND_DNS_OVER_TLS_PORT (853)

#ifndef ROOT_ANCHOR_FILE
#define ROOT_ANCHOR_FILE "/var/lib/unbound/root.key"
#endif

#ifndef ROOT_CERT_FILE
#define ROOT_CERT_FILE "/etc/ssl/certs/ca-certificates.crt"
#endif

#define ARG_LL "%ll"

#define HAVE_SSL
#include <openssl/ssl.h>
#define HAVE_OPENSSL_ERR_H
#define HAVE_OPENSSL_BN_H
#define HAVE_OPENSSL_DH_H
#define HAVE_OPENSSL_RAND_H
#define HAVE_OPENSSL_CONF_H
#define HAVE_OPENSSL_SSL_H
#define HAVE_OPENSSL_ENGINE_H
#define HAVE_EVP_SHA256
#define HAVE_EVP_MD_CTX_NEW
#define HAVE_EVP_MD_CTX_NEW
#define USE_ED25519
#define HAVE_EVP_SHA256
#define HAVE_EVP_SHA512
#define USE_SHA256
#define HAVE_EVP_SRF
#define HAVE_OPENSSL_RSA_H
#define LDNS_BUILD_CONFIG_HAVE_SSL 1

#define HAVE_SYS_STAT_H
#define HAVE_SYS_TYPES_H

#define HAVE_EVENT_H
#define HAVE_EXPAT_H

#define HAVE_FSYNC
#define HAVE_SOCKETPAIR

#define S_SPLINT_S

#define RETSIGTYPE void

#endif
