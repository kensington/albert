// albert - a simple application launcher for linux
// Copyright (C) 2014 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ABSTRACTSERVICEPROVIDER_H
#define ABSTRACTSERVICEPROVIDER_H

#include <string>
#include <vector>

class AbstractServiceProvider
{
public:
	class AbstractItem
	{
	public:
		enum class Action { Enter, Alt, Ctrl };

		AbstractItem() = delete;
		AbstractItem(const std::string &title) : _title(title){}
		virtual ~AbstractItem(){}

		inline  std::string  title() const {return _title;}
		virtual std::string  mimeType() const = 0;
		virtual std::string  complete() const = 0;
		virtual void         action(Action) = 0;
		virtual std::string  actionText(Action) const = 0;
		virtual std::string  infoText() const = 0;
		void                 fallbackAction(Action) const;
		std::string          fallbackActionText(Action) const;

	protected:
		const std::string _title;
		static void startDetached(std::string cmd, std::string param);
	};

	AbstractServiceProvider(){}
	virtual ~AbstractServiceProvider(){}
	virtual std::vector<AbstractItem*> query(const std::string &req) = 0;
};

#endif // ABSTRACTSERVICEPROVIDER_H