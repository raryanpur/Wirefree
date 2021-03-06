/*
Client.h - network client class 

Copyright (C) 2011 DIYSandbox LLC

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef _client_h_
#define _client_h_

#include "WProgram.h"	
#include "Print.h"

class Client : public Stream {

public:
  Client();
  Client(uint8_t);
  Client(uint8_t *, uint16_t);

  uint8_t status();
  uint8_t connect();
  virtual void write(uint8_t);
  virtual void write(const char *str);
  virtual void write(const uint8_t *buf, size_t size);
  virtual int available();
  virtual int read();
  virtual int peek();
  virtual void flush();
  void stop();
  uint8_t connected();
  uint8_t operator==(int);
  uint8_t operator!=(int);
  operator bool();

  friend class Server;

private:
  static uint16_t _srcport;
  uint8_t _sock;
  uint8_t *_ip;
  uint16_t _port;
};

#endif //_client_h_

