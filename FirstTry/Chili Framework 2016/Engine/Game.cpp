/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

#include "TommyCoordinate.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{
	bool isUp = wnd.kbd.KeyIsPressed(VK_UP);
	bool isDown = wnd.kbd.KeyIsPressed(VK_DOWN);
	bool isLeft = wnd.kbd.KeyIsPressed(VK_LEFT);
	bool isRight = wnd.kbd.KeyIsPressed(VK_RIGHT);
	XYCoord Center; Center.X = 400; Center.Y = 250;
	int size = 50;
	int offset = 0;
	if (isUp) {
		int offset = 50;
		for (int i = Center.X - (size / 2); i < Center.X + (size / 2); i++) {
			gfx.PutPixel(i, Center.Y + size / 2 - offset, 255, 255, 255);
			gfx.PutPixel(i, Center.Y - size / 2 - offset, 255, 255, 255);
		}
		for (int i = Center.Y - (size / 2); i < Center.Y + (size / 2); i++) {
			gfx.PutPixel(Center.X + size / 2, i - offset, 255, 255, 255);
			gfx.PutPixel(Center.X - size / 2, i - offset, 255, 255, 255);
		}
	}
	else if (isDown) {
		int offset = 50;
		for (int i = Center.X - (size / 2); i < Center.X + (size / 2); i++) {
			gfx.PutPixel(i, Center.Y + size / 2 + offset, 255, 255, 255);
			gfx.PutPixel(i, Center.Y - size / 2 + offset, 255, 255, 255);
		}
		for (int i = Center.Y - (size / 2); i < Center.Y + (size / 2); i++) {
			gfx.PutPixel(Center.X + size / 2, i + offset, 255, 255, 255);
			gfx.PutPixel(Center.X - size / 2, i + offset, 255, 255, 255);
		}
	}
	else if (isLeft) {
		int offset = 50;
		for (int i = Center.X - (size / 2); i < Center.X + (size / 2); i++) {
			gfx.PutPixel(i - offset, Center.Y + size / 2 , 255, 255, 255);
			gfx.PutPixel(i - offset, Center.Y - size / 2 , 255, 255, 255);
		}
		for (int i = Center.Y - (size / 2); i < Center.Y + (size / 2); i++) {
			gfx.PutPixel(Center.X + size / 2 - offset, i , 255, 255, 255);
			gfx.PutPixel(Center.X - size / 2 - offset, i , 255, 255, 255);
		}
	}
	else if (isRight) {
		int offset = 50;
		for (int i = Center.X - (size / 2); i < Center.X + (size / 2); i++) {
			gfx.PutPixel(i + offset, Center.Y + size / 2 , 255, 255, 255);
			gfx.PutPixel(i + offset, Center.Y - size / 2 , 255, 255, 255);
		}
		for (int i = Center.Y - (size / 2); i < Center.Y + (size / 2); i++) {
			gfx.PutPixel(Center.X + size / 2 + offset, i , 255, 255, 255);
			gfx.PutPixel(Center.X - size / 2 + offset, i , 255, 255, 255);
		}
	}
	else {
		for (int i = Center.X - (size / 2); i < Center.X + (size / 2); i++) {
			gfx.PutPixel(i, Center.Y + size / 2, 255, 255, 255);
			gfx.PutPixel(i, Center.Y - size / 2, 255, 255, 255);
		}
		for (int i = Center.Y - (size / 2); i < Center.Y + (size / 2); i++) {
			gfx.PutPixel(Center.X + size / 2, i, 255, 255, 255);
			gfx.PutPixel(Center.X - size / 2, i, 255, 255, 255);
		}
	}
}
