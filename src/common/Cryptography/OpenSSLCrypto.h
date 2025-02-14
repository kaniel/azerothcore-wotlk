/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPENSSL_CRYPTO_H_
#define OPENSSL_CRYPTO_H_

#include "Define.h"
#include <openssl/opensslv.h>

/**
* A group of functions which setup openssl crypto module to work properly in multithreaded enviroment
* If not setup properly - it will crash
*/
namespace OpenSSLCrypto
{

#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x1010000fL
    /// Needs to be called before threads using openssl are spawned
    void threadsSetup();
    /// Needs to be called after threads using openssl are despawned
    void threadsCleanup();
#else
    void threadsSetup() { };
    void threadsCleanup() { };
#endif

}

#endif
