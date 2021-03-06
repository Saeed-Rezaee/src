/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/* $Id: unspec_103.c,v 1.11 2020/02/26 18:47:25 florian Exp $ */

#ifndef RDATA_GENERIC_UNSPEC_103_C
#define RDATA_GENERIC_UNSPEC_103_C

static inline isc_result_t
totext_unspec(ARGS_TOTEXT) {

	REQUIRE(rdata->type == dns_rdatatype_unspec);

	UNUSED(tctx);

	return (btoa_totext(rdata->data, rdata->length, target));
}

static inline isc_result_t
fromwire_unspec(ARGS_FROMWIRE) {
	isc_region_t sr;

	REQUIRE(type == dns_rdatatype_unspec);

	UNUSED(type);
	UNUSED(rdclass);
	UNUSED(dctx);
	UNUSED(options);

	isc_buffer_activeregion(source, &sr);
	isc_buffer_forward(source, sr.length);
	return (isc_mem_tobuffer(target, sr.base, sr.length));
}

static inline isc_result_t
towire_unspec(ARGS_TOWIRE) {

	REQUIRE(rdata->type == dns_rdatatype_unspec);

	UNUSED(cctx);

	return (isc_mem_tobuffer(target, rdata->data, rdata->length));
}

#endif	/* RDATA_GENERIC_UNSPEC_103_C */
