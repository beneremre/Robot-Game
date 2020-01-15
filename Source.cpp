#include <iostream>
#include <cmath>
#include "Robots.h"
#include "MiniFW.h"

void CornerTour (Robot & runner, int xCampNou, int yCampNou) ; //prototype of first function


void CatchRobot (Robot & Iniesta, Robot & Xavi, Robot & Messi, int xIniesta, int yIniesta, int xXavi, int yXavi, int xMessi, int yMessi) //First function that takes one robot to the corner
{

	int xdis = abs (xMessi - xIniesta), ydis = abs (yMessi - yIniesta) ; //definitin of integers
	int xdis2 = abs ( xMessi - xXavi), ydis2 = abs ( yMessi - yXavi ); //definitin of integers


	if (xdis + ydis <= xdis2 + ydis2) //statement that decides which robot is closer to the enemy
	{
		if (xMessi - xIniesta < 0) //if statement is true this means friend robot is on the right side of enemy
		{
			Iniesta.TurnRight() ;
			Iniesta.TurnRight() ;
			Iniesta.Move(xdis) ;

			if (yMessi - yIniesta < 0) //if statement is true this means friend robot is on the upper side of enemy
			{
				Iniesta.TurnRight() ;
				Iniesta.TurnRight() ;
				Iniesta.TurnRight() ;
				Iniesta.Move(ydis) ;
			} 
			else if (yMessi - yIniesta > 0) //if statement is true this means friend robot is on the lower side of enemy
			{
				Iniesta.TurnRight() ;
				Iniesta.Move(ydis) ;
			}
			else if (yMessi - yIniesta == 0) //if statement is true this means the robots are on the same y axis
			{
			Iniesta.TurnRight() ;
			Iniesta.TurnRight() ;
			Iniesta.Move(ydis) ;
			}
		}
		else if (xMessi - xXavi > 0) //if statement is true this means enemy robot is on the right side of friend robot
		{

			Iniesta.Move(xdis) ;

			if (yMessi - yIniesta < 0) //if statement is true this means friend robot is on the upper side of enemy
			{
				Iniesta.TurnRight() ;
				Iniesta.Move(ydis) ;
			}
			else if (yMessi - yIniesta > 0) //if statement is true this means enemy robot is on the upper side of the enemy
			{
				Iniesta.TurnRight() ;
				Iniesta.TurnRight() ;
				Iniesta.TurnRight() ;
				Iniesta.Move(ydis) ;
			}	
			if (yMessi - yIniesta == 0) //if statement is true this means both robots are on the same y axis.
			{
	
			Iniesta.Move(ydis) ;
			}
		}

		else if (xMessi - xIniesta == 0) //if statement is true this means both robots are on the same x axis.
		{
			if (yMessi - yIniesta < 0) //if statement is true this means friend robot on the upper side of the enemy	
			{
				Iniesta.TurnRight() ;
				Iniesta.Move(ydis) ;
			}
			else if (yMessi - yIniesta > 0) //if statement is true this means enemy robot is on the upper side of the friend robot.
			{
				Iniesta.TurnRight() ;
				Iniesta.TurnRight() ;
				Iniesta.TurnRight() ;
				Iniesta.Move(ydis) ;
			}
		}
			CornerTour(Xavi, xXavi, yXavi) ; //calling function 2, which takes other friend robot to the corners in a row.
	}
	else if (xdis + ydis > xdis2 + ydis2)  //statement that decides which robot is closer to the enemy
	{
		if (xMessi - xXavi < 0) //if statement is true this means friend robot is on the right side of enemy
		{

			Xavi.TurnRight() ;
			Xavi.TurnRight() ;
			Xavi.Move(xdis2) ;

			if (yMessi - yXavi < 0) //if statement is true this means friend robot is on the upper side of the enemy
			{
				Xavi.TurnRight() ;
				Xavi.TurnRight() ;
				Xavi.TurnRight() ;
				Xavi.Move(ydis2) ;
			} 
			else if (yMessi - yXavi > 0) //if statement is true this meansenemy robot is on the upper side of the friend robot
			{
				Xavi.TurnRight() ;
				Xavi.Move(ydis2) ;
			}
				else if (yMessi - yXavi > 0) //if statement is true this means enemy robot is on the upper side of the friend robot
			{
				
			Xavi.TurnRight() ;
			Xavi.TurnRight() ;
			Xavi.Move(ydis2) ;
			}

		}
		else if (xMessi - xXavi > 0) //if statement is true this means enemy robot is on the right side of the friend robot
		{

			Xavi.Move(xdis2) ;

			if (yMessi - yXavi > 0) //if statement is true this means enemy robot is on the upper sdie of the friend robot
			{
				Xavi.TurnRight() ;
				Xavi.TurnRight() ;
				Xavi.TurnRight() ;
				Xavi.Move(ydis2) ;
			}
			else if (yMessi - yXavi < 0) //if statement is true this means friend robot is on the upper side of the enemy
			{
				Xavi.TurnRight() ;
				Xavi.Move(ydis2) ;
			}
			else if (yMessi - yXavi == 0) //if statement is true this means both robots are on the same y axis
			{
					Xavi.Move(ydis2) ;
			}
		}

		else if (xMessi - xXavi == 0) //if statement is true this means both robots are on the same x axis
		{
			if (yMessi - yXavi < 0) //if statement is true this means friend robot is on the upper side of the enemy
			{
				Xavi.TurnRight() ;
				Xavi.Move(ydis2) ;
			}
			else if (yMessi - yXavi > 0) //if statement is true this means enemy robot is on the upper side of the friend robot
			{
				Xavi.TurnRight() ;
				Xavi.TurnRight() ;
				Xavi.TurnRight() ;
				Xavi.Move(ydis2) ;
			}
		}
	}
		CornerTour (Iniesta, xIniesta, yIniesta) ; //calling function 2 
}

void CornerTour (Robot & runner, int xCampNou, int yCampNou) //function that takes the other friend robot to the corners in a row
{
	if ( xCampNou < 5 && yCampNou < 5 ) //if statement is true this means the other robot will go to the (0,0)corner
	{
		runner.TurnRight() ;
		runner.Move(yCampNou) ;
		runner.TurnRight() ;
		runner.Move(xCampNou) ;
		runner.SetColor(orange) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(blue);
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(red) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(green) ;

	}
	else if ( xCampNou < 5 && yCampNou >= 5 && yCampNou < 10 ) //if statement is true this means the other robot will go to the (0,9) corner
	{
		runner.TurnRight() ;
		runner.TurnRight() ;
		runner.Move(xCampNou) ;
		runner.TurnRight() ;
		runner.Move( 9 - yCampNou ) ;
		runner.SetColor(blue) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(red) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(green) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(orange) ;

	}
	else if ( xCampNou >= 5 && xCampNou < 10 && yCampNou < 5 ) //if statement is true this means the other robot will go to the (9,0) corner
	{
		runner.Move( 9 - xCampNou ) ;
		runner.TurnRight() ;
		runner.Move(yCampNou) ;
		runner.SetColor(green) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(orange) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(blue) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(red) ;
	}
	else if (xCampNou >= 5 && xCampNou < 10 && yCampNou >= 5 && yCampNou < 10 )//if statement is true this means the other robot will go to the (9,9) corner
	{
		runner.Move( 9 - xCampNou ) ;
		runner.TurnRight() ;
		runner.TurnRight() ;
		runner.TurnRight() ;
		runner.Move( 9 - yCampNou ) ;
		runner.SetColor(red) ;
		runner.TurnRight() ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(green) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(orange) ;
		runner.TurnRight() ;
		runner.Move(9) ;
		runner.SetColor(blue) ;
	}
}






int main ()
{
	int xIniesta, yIniesta, xXavi, yXavi, xMessi, yMessi ; //definitipon of integers

	ShowMessage("Welcome to my robot program, please follow the prompt") ;

	GetInput("Please enter the x coordinate for the first robot" , xIniesta) ;
	GetInput("Please enter the y coordinate for the first robot" , yIniesta) ;

	if ( xIniesta < 0 || xIniesta > 10 || yIniesta < 0 || yIniesta > 10 ) //error calls
	{
		ShowMessage("Error in x,y coordinates of the first robot") ;
		return 0;
	}
	else if ( (xIniesta == 0 && yIniesta == 0) || (xIniesta == 0 && yIniesta == 9) || (xIniesta == 9 && yIniesta == 0) || (xIniesta == 9 && yIniesta == 9) ) //error calls
	{
		ShowMessage("Error!! first robot cannot be created on the corners") ;
		return 0;
	}
	else ;

	Robot Iniesta (xIniesta, yIniesta) ; //calling first friend robot





	GetInput("Please enter the x coordinate for the second robot" , xXavi) ;
	GetInput("Please enter the y coordinate for the second robot" , yXavi) ;

	if ( xXavi < 0 || xXavi > 10 || yXavi < 0 || yXavi > 10 ) //error calls
	{
		ShowMessage("Error in x,y coordinates of the first robot") ;
		return 0;
	}

	else if ( xIniesta == xXavi && yIniesta == yXavi ) //error calls
	{
		ShowMessage ("Error!! second and first robot are on the same position") ;
		return 0;
	}

	else if ( (xXavi == 0 && yXavi == 0) || (xXavi == 0 && yXavi == 9) || (xXavi == 9 && yXavi == 0) || (xXavi == 9 && yXavi == 9) ) //error calls
	{
		ShowMessage("Error!! first robot cannot be created on the corners") ;
		return 0;
	}

	else ;

	Robot Xavi (xXavi, yXavi) ; //calling second friend robot





	GetInput("Please enter the x coordinate for the target robot" , xMessi) ;
	GetInput("Please enter the y coordinate for the target robot" , yMessi) ;

	if ( xMessi < 0 || xMessi > 10 || yMessi < 0 || yMessi > 10 ) //error calls
	{
		ShowMessage("Error in x,y coordinates of the target robot") ;
		return 0;
	}

	else if ( xIniesta == xMessi && yIniesta == yMessi ) //error calls
	{
		ShowMessage ("Error!! third and first robot are in the same position") ;
		return 0;
	}

	else if ( xXavi == xMessi && yXavi == yMessi ) //error calls
	{
		ShowMessage ("Error!! third and second robot are in the same position") ;
		return 0;
	}

	else if ( (xMessi == 0 && yMessi == 0) || (xMessi == 0 && yMessi == 9) || (xMessi == 9 && yMessi == 0) || (xMessi == 9 && yMessi == 9) ) //error calls
	{
		ShowMessage("Error!! target robot cannot be created on the corners") ;
		return 0;
	}

	else ;

	Robot Messi (xMessi, yMessi) ; //calling enemy robot

	Messi.SetColor (red) ;

	CatchRobot (Iniesta, Xavi, Messi, xIniesta, yIniesta, xXavi, yXavi, xMessi, yMessi) ; //calling first function


}