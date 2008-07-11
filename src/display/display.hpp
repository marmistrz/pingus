//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_PINGUS_DISPLAY_HPP
#define HEADER_PINGUS_DISPLAY_HPP

#include <memory>
#include <list>
#include <vector>
#include "../math/size.hpp"

class Vector2i;
class Rect;
class Color;
class Framebuffer;

class Display
{
private:
  static std::auto_ptr<Framebuffer> framebuffer;

public:
  static void flip_display();

  static int  get_width();
  static int  get_height();
  static Size get_size();

  static void set_video_mode(int width, int height, bool fullscreen);
  
  static Framebuffer& get_framebuffer();

private:
  Display ();
  Display (const Display&);
  Display& operator= (const Display&);
};

#endif

/* EOF */
