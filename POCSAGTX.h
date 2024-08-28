/*
 *   Copyright (C) 2015-2020 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "Config.h"

#if defined(MODE_POCSAG)

#if !defined(POCSAGTX_H)
#define  POCSAGTX_H

#include "RingBuffer.h"

class CPOCSAGTX {
public:
  CPOCSAGTX();

  uint8_t writeData(const uint8_t* data, uint16_t length);

  void writeByte(uint8_t c);

  void process();

  void setTXDelay(uint8_t delay);

  uint8_t getSpace() const;

  bool busy();

private:
  CRingBuffer<uint8_t>            m_buffer;
  arm_fir_instance_q15 m_modFilter;
  q15_t                m_modState[170U];     // NoTaps + BlockSize - 1, 6 + 160 - 1 plus some spare
  uint8_t              m_poBuffer[200U];
  uint16_t             m_poLen;
  uint16_t             m_poPtr;
  uint16_t             m_txDelay;
};

#endif

#endif

