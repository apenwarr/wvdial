/*
 * Worldvisions Weaver Software:
 *   Copyright (C) 1997, 1998 Worldvisions Computer Technology, Inc.
 *
 * Re-write of wvpapsecrets.h.  This one supports CHAP as well, and is also
 * much safer.
 */

#ifndef __WVPAPCHAP_H
#define __WVPAPCHAP_H

#include "wvconf.h"
#include "wvlinklist.h"
#include "wvstring.h"

#define PAP_SECRETS	"/etc/ppp/pap-secrets"
#define CHAP_SECRETS	"/etc/ppp/chap-secrets"
#define REMOTE_SECRET	"wvdial"

class WvPapChap
/*************/
{
public:
    WvPapChap()
    	: pap_success( true ), chap_success( true ) {}
    ~WvPapChap() {}

    void put_secret( WvString username, WvString password, WvString remote );
    bool isok_pap() const
    	{ return( pap_success ); }
    bool isok_chap() const
    	{ return( chap_success ); }

private:
    WvStringList contents;
    bool	 pap_success;
    bool	 chap_success;

    bool load_file( char * filename );
    void nuke_contents();
    bool write_file( char * filename );
    void do_secret( char * username, char * password, char * remote );
};

#endif __WVPAPCHAP_H