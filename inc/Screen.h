/*
    Stk - SDL-based GUI Toolkit
    Copyright (C) 2017  Robin Krause

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _StkScreen
#define _StkScreen

class Screen
{
private:
    std::vector<Widget*> widgets;

public:
    Screen(){}
    ~Screen()
    {
        widgets.clear();
    }
    void add(Widget* w)
    {
        widgets.push_back(w);
    }
    void remove(int index)
    {
        std::vector<Widget*> to_remove;

        for(int i=0;i<widgets.size();i++)
        {
            if(i!=index)
            {
                to_remove.push_back(widgets.at(i));
            }
        }
        widgets=to_remove;
    }
    std::vector<Widget*> getAll()
    {
        return widgets;
    }
    Widget* get(int index)
    {
        return widgets.at(index);
    }
};

#endif