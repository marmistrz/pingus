//  $Id: entrance_data.cxx,v 1.10 2003/10/18 23:17:28 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <iostream>
#include "../world.hxx"
#include "../worldobjs/entrances/woodthing.hxx"
#include "../worldobjs/entrances/cloud.hxx"
#include "../pingus_error.hxx"
#include "../xml_helper.hxx"
#include "../xml_file_reader.hxx"
#include "entrance_data.hxx"

namespace Pingus {
namespace WorldObjsData {

EntranceData::EntranceData () : direction(MISC),
                                release_rate(50),
				owner_id(0),
				type("generic")
{
}

EntranceData::EntranceData (xmlDocPtr doc, xmlNodePtr cur) : direction(MISC),
                                                             release_rate(50),
							     owner_id(0),
							     type("generic")
{
  XMLFileReader reader(doc,cur);
  reader.read_string("type", type);
  reader.read_int("owner-id", owner_id);
  reader.read_vector("position", pos);
  reader.read_int("release-rate", release_rate);

  std::string direction_str;
  reader.read_string("direction", direction_str);

  if (direction_str == "left")
    direction = EntranceData::LEFT;
  else if (direction_str == "right")
    direction = EntranceData::RIGHT;
  else if (direction_str == "misc")
    direction = EntranceData::MISC;
  else
    {
      std::cout << "EntranceData: Unknown direction: '" << direction_str << "'" << std::endl;
      direction = EntranceData::MISC;
    }
}

void
EntranceData::insert_WorldObjs (World* world)
{
  if (type == "generic") {
    world->add_object(new WorldObjs::Entrance(*this));
  } else if (type == "woodthing") {
    world->add_object(new WorldObjs::Entrances::WoodThing(*this));
  } else if (type == "cloud") {
    world->add_object(new WorldObjs::Entrances::Cloud(*this));
  }
  //PingusError::raise("Entrance: Entrance type in Level file is unknown: " + type);
}

} // namespace WorldObjsData
} // namespace Pingus

/* EOF */
