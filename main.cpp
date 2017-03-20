/*Alexanrda Macedo
February 1, 2015

This program displays a tic-tac-toe board and asks the user,
the guajolotes, to click on one of the squares to play the
first move in tic-tac-toe, represented as a bus. 
Each click is read by the program and coordinates are stored 
to make the squares that are clicked on no longer playable. 
The opponent is not the user or another user, but the program, 
itself, and it makes a move, in the first available playable 
square. The game is terminated when, either player gets 3 in 
a row or all 9 moves have been played. It also displays a line 
going through any 3 in a row that is accomplished and displays 
the winner. At the end of each game the program asks the user 
if they would like to play again. They can replay the game 
infinite times, or say no and endthe program.*/



#include "ccc_win.h"


/*This fucntion displays the tic-tac-toe board.*/
void drawBoard(){


	/*This constant represents half of the width of the board.*/
		const double boardRadius = 8;

	/*Horizontal Lines of the Board*/

		/*Top Line*/
			Point top1(-boardRadius, boardRadius / 3);
			Point top2(boardRadius, boardRadius / 3);
			Line top(top1, top2);

		/*Bottom Line*/
			Point bottom1(-boardRadius, -boardRadius / 3);
			Point bottom2(boardRadius, -boardRadius / 3);
			Line bottom(bottom1, bottom2);

	/*Vertical Lines of the Board*/

		/*Left Line*/
			Point left1(-boardRadius / 3, boardRadius);
			Point left2(-boardRadius / 3, -boardRadius);
			Line left(left1, left2);

		/*Right Line*/

			Point right1(boardRadius / 3, boardRadius);
			Point right2(boardRadius / 3, -boardRadius);
			Line right(right1, right2);

	
		cwin << top << bottom << left << right;

}

/*This function displays the image of the guajolotero bus.*/
void drawGuajolotero(double xCoord, double yCoord){

	/*Horizontal Lines of the Bus*/

	cwin << Line(Point(xCoord - 2.5, yCoord - 1.2), Point(xCoord + 1.7, yCoord - 1.2));
	cwin << Line(Point(xCoord - 2.5, yCoord + .25), Point(xCoord + 1.7, yCoord + .25));
	cwin << Line(Point(xCoord - 2.5, yCoord - 1.5), Point(xCoord + 2.7, yCoord - 1.5));
	cwin << Line(Point(xCoord + 1.7, yCoord - 1), Point(xCoord + 2.7, yCoord - 1));
	cwin << Line(Point(xCoord - 2.5, yCoord + 2), Point(xCoord + 1.7, yCoord + 2));
	cwin << Line(Point(xCoord - 2.5, yCoord + .5), Point(xCoord + 2.7, yCoord + .5));

		/*Horizontal Lines for Windows of the Bus*/

		cwin << Line(Point(xCoord - 2.3, yCoord + .7), Point(xCoord - .6, yCoord + .7));
		cwin << Line(Point(xCoord + 1.5, yCoord + .7), Point(xCoord - .2, yCoord + .7));
		cwin << Line(Point(xCoord - 2.3, yCoord + 1.8), Point(xCoord - .6, yCoord + 1.8));
		cwin << Line(Point(xCoord + 1.5, yCoord + 1.8), Point(xCoord - .2, yCoord + 1.8));


	/*Vertical Lines of the Bus*/

	cwin << Line(Point(xCoord - 2.5, yCoord - 1), Point(xCoord - 2.5, yCoord - 1.5));
	cwin << Line(Point(xCoord + 1.7, yCoord - 1), Point(xCoord + 1.7, yCoord - 1.5));
	cwin << Line(Point(xCoord - 2.5, yCoord - 1), Point(xCoord - 2.5, yCoord + 2));
	cwin << Line(Point(xCoord + 1.7, yCoord - 1), Point(xCoord + 1.7, yCoord + 2));
	cwin << Line(Point(xCoord + 2.7, yCoord + .5), Point(xCoord + 2.7, yCoord - 1.5));

		/*Vertical Lines of the Windows of the Bus*/

		cwin << Line(Point(xCoord - 2.3, yCoord + .7), Point(xCoord - 2.3, yCoord + 1.8));
		cwin << Line(Point(xCoord - .6, yCoord + .7), Point(xCoord - .6, yCoord + 1.8));
		cwin << Line(Point(xCoord - .2, yCoord + .7), Point(xCoord - .2, yCoord + 1.8));
		cwin << Line(Point(xCoord + 1.5, yCoord + .7), Point(xCoord + 1.5, yCoord + 1.8));


	/*Wheels of the Bus*/

	cwin << Circle(Point(xCoord - 2, yCoord - 2), .5);
	cwin << Circle(Point(xCoord + 1.2, yCoord - 2), .5);
	cwin << Circle(Point(xCoord - 2, yCoord - 2), .2);
	cwin << Circle(Point(xCoord + 1.2, yCoord - 2), .2);


	/*Passengers on the Bus*/

	cwin << Circle(Point(xCoord - 1.45, yCoord + 1.15), .45);
	cwin << Circle(Point(xCoord + .65, yCoord + 1.15), .45);
	cwin << Circle(Point(xCoord - 1.2, yCoord + 1.2), .07);
	cwin << Circle(Point(xCoord + .9, yCoord + 1.2), .07);


	/*Name printed on the side of the bus*/

	cwin << Message(Point(xCoord - 2.45, yCoord - .1), "Guajolotero Bus");

	/*Dinginess and scratches of the Guajolotero to identify it apart from other buses*/

	cwin << Line(Point(xCoord - 2.4, yCoord - 1.4), Point(xCoord - 2.2, yCoord - 1.2));
	cwin << Line(Point(xCoord - 2.45, yCoord - .8), Point(xCoord - 2, yCoord - .95));
	cwin << Line(Point(xCoord - 2, yCoord - .95), Point(xCoord - 1.75, yCoord - .85));
	cwin << Line(Point(xCoord - 2.1, yCoord - .1), Point(xCoord + .4, yCoord - .6));
	cwin << Line(Point(xCoord - 1.5, yCoord - 1.3), Point(xCoord - .9, yCoord - .9));
	cwin << Line(Point(xCoord - .9, yCoord - .9), Point(xCoord - .7, yCoord - .9));
	cwin << Line(Point(xCoord - .7, yCoord - .9), Point(xCoord - .65, yCoord - 1.1));
	cwin << Line(Point(xCoord - 2, yCoord - 1.4), Point(xCoord + 1.5, yCoord - 1));
	cwin << Line(Point(xCoord, yCoord + .2), Point(xCoord + .2, yCoord + .15));
	cwin << Line(Point(xCoord + .2, yCoord + .15), Point(xCoord + .35, yCoord + .2));
	cwin << Line(Point(xCoord + .35, yCoord + .2), Point(xCoord + .5, yCoord + .18));
	cwin << Line(Point(xCoord + .5, yCoord + .18), Point(xCoord + 1.1, yCoord - .25));
	cwin << Line(Point(xCoord + 1.1, yCoord - .25), Point(xCoord + 1.3, yCoord));
	cwin << Line(Point(xCoord + .8, yCoord - .1), Point(xCoord + .5, yCoord - 1.4));
	cwin << Line(Point(xCoord - 1.4, yCoord - .6), Point(xCoord - .3, yCoord - .1));
	cwin << Line(Point(xCoord - .3, yCoord - .1), Point(xCoord - .1, yCoord - .2));
	cwin << Line(Point(xCoord - .9, yCoord), Point(xCoord - .75, yCoord + .45));
	cwin << Line(Point(xCoord - 1.1, yCoord + .25), Point(xCoord - .6, yCoord + .1));

}


/*This is the main function that runs the tic-tac-toe game.*/
int ccc_win_main(){

	/*Variables that represent coordinates on the board*/
	double x, y;

	/*Constant value of half the width of the board*/
	const double boardRadius = 8;

	/*Boolean variable to initialize the game*/
		bool playGame = true;

		while (playGame == true) {

			drawBoard();

		/*These boolean values stated as false represent that each 
		of the nine squares on the board starts out as empty,
		without any move played.*/

			bool topLeft = false;
			bool topMiddle = false;
			bool topRight = false;
			bool middleLeft = false;
			bool middleMiddle = false;
			bool middleRight = false;
			bool bottomLeft = false;
			bool bottomMiddle = false;
			bool bottomRight = false;

		/*Variables that keep track of how many times a move has been played by
		the guajolotes in each column, row, and diagonal on the tic-tac-toe board.*/
		
			/*Rows*/
			int oTopHorizontalMoves = 0;
			int oMiddleHorizontalMoves = 0;
			int oBottomHorizontalMoves = 0;

			/*Columns*/
			int oLeftVerticalMoves = 0;
			int oMiddleVerticalMoves = 0;
			int oRightVerticalMoves = 0;
			
			/*Diagonals*/
			int oTopBottomDiagonalMoves = 0;
			int oBottomTopDiagonalMoves = 0;

		/*Variables that keep track of how many times a move has been played by
		the "X" player in each column, row, and diagonal on the tic-tac-toe board.*/

			/*Rows*/
			int xTopHorizontalMoves = 0;
			int xMiddleHorizontalMoves = 0;
			int xBottomHorizontalMoves = 0;

			/*Columns*/
			int xLeftVerticalMoves = 0;
			int xMiddleVerticalMoves = 0;
			int xRightVerticalMoves = 0;

			/*Diagonals*/
			int xTopBottomDiagonalMoves = 0;
			int xBottomTopDiagonalMoves = 0;

		/*The game will run until it reaches 9 turns or either the guajolotes or the
		"X" player gets three moves in one column, row, or diagonal to make
		 3 in a row.*/
			bool oTurn = true;
			for (int turn = 1; turn <= 9 
				&& oTopHorizontalMoves!=3
				&& oMiddleHorizontalMoves<3
				&& oBottomHorizontalMoves<3
				&& oLeftVerticalMoves<3
				&& oMiddleVerticalMoves<3
				&& oRightVerticalMoves!=3
				&& oTopBottomDiagonalMoves<3
				&& oBottomTopDiagonalMoves<3
				&& xTopHorizontalMoves != 3
				&& xMiddleHorizontalMoves<3
				&& xBottomHorizontalMoves<3
				&& xLeftVerticalMoves<3
				&& xMiddleVerticalMoves<3
				&& xRightVerticalMoves != 3
				&& xTopBottomDiagonalMoves<3
				&& xBottomTopDiagonalMoves<3; ++turn){


			/*The following if statement and it's contents are carried out
			 if it is the guajolotes' turn.*/

				if (oTurn){

					/*Stores the points and X and Y coordinates of where the user clicks.*/
						Point oMove = cwin.get_mouse("Click to play the guajolotero bus");

						x = oMove.get_x();
						y = oMove.get_y();

					/*The guajolotero bus is displayed where the user clicks.*/
						drawGuajolotero(x,y);

					/*The following if statements set constraints to test for where the user clicked.
					Depending on the coordinates, 1 will be added to the number of moves the 
					guajolotes have made in any column, row, or diagonal on the board. Each statement
					also tells the program that whatever square was played is no longer playable.*/

						if (x<-boardRadius / 3 && y>boardRadius / 3){
						
							/*Increments the number of moves by the guajolotes in a row, column,
							and/or diagonal.*/
							oTopHorizontalMoves++;
							oLeftVerticalMoves++;
							oTopBottomDiagonalMoves++;

							/*Makes the top left square unplayable by Player "X"*/
							topLeft = true;

						}

						else if (x>-boardRadius / 3 && x<boardRadius / 3 && y>boardRadius / 3){

							oTopHorizontalMoves++;
							oMiddleVerticalMoves++;

							topMiddle = true;

						}

						else if (x>boardRadius / 3 && y>boardRadius / 3){
										
							oTopHorizontalMoves++;
							oRightVerticalMoves++;
							oBottomTopDiagonalMoves++;

							topRight = true;

						}

						else if (x<-boardRadius / 3 && y<boardRadius / 3 && y>-boardRadius / 3){				
						
							oMiddleHorizontalMoves++;
							oLeftVerticalMoves++;

							middleLeft = true;

						}

						else if (x>-boardRadius / 3 && x<boardRadius / 3 && y<boardRadius / 3 && y>-boardRadius / 3){
											
							oMiddleHorizontalMoves++;
							oMiddleVerticalMoves++;
							oTopBottomDiagonalMoves++;
							oBottomTopDiagonalMoves++;

							middleMiddle = true;

						}

						else if (x>boardRadius / 3 && y<boardRadius / 3 && y>-boardRadius / 3){
											
							oMiddleHorizontalMoves++;
							oRightVerticalMoves++;

							middleRight = true;

						}

						else if (x<-boardRadius / 3 && y<-boardRadius / 3){
											
							oLeftVerticalMoves++;
							oBottomHorizontalMoves++;
							oBottomTopDiagonalMoves++;

							bottomLeft = true;

						}

						else if (x>-boardRadius / 3 && x<boardRadius / 3 && y<-boardRadius / 3){
											
							oBottomHorizontalMoves++;
							oMiddleVerticalMoves++;

							bottomMiddle = true;

						}

						else if (x>boardRadius / 3 && y<-boardRadius / 3){
											
							oBottomHorizontalMoves++;
							oRightVerticalMoves++;
							oTopBottomDiagonalMoves++;

							bottomRight = true;

						}
					}

				/*The following else statement and its contents are carried out
				if it is the "X' player's turn.*/

				else {

					/*The following if statements are carried out when their argument is
					false. The boolean variables inside the if arguments will have been
					previously changed to true and not be carried out if the user or
					the program, Player "X," has played in that square.The program,
					Player "X" will find the first square that is playable, denoted by
					the first appearance if an argument that is false. Depending on
					which square is first available, the program will display an X in
					that square, make it no longer playable, and 1 will be added to the
					number of moves that player "X" has made in each row, column, and
					diagonal.*/

						if (middleMiddle == false){

								x = 0;
								y = 0;

								/*Lines to draw X in the center square on the board*/
								Line x1(Point(x - 2, y - 2), Point(x + 2, y + 2));
								Line x2(Point(x - 2, y + 2), Point(x + 2, y - 2));

								cwin << x1 << x2;

								/*Makes this square on the board no longer playable*/
								middleMiddle = true;

								/*Incrementing the number of moves in a column, row, and/or diagonal*/
								xMiddleHorizontalMoves++;
								xMiddleVerticalMoves++;
								xTopBottomDiagonalMoves++;
								xBottomTopDiagonalMoves++;

							}

							else if (topLeft==false){
								x = -boardRadius * 2 / 3;
								y = boardRadius * 2 / 3;

								Line x1(Point(x - 2, y - 2), Point(x + 2, y + 2));
								Line x2(Point(x - 2, y + 2), Point(x + 2, y - 2));

								cwin << x1 << x2;

								topLeft = true;

								xTopHorizontalMoves++;
								xLeftVerticalMoves++;
								xTopBottomDiagonalMoves++;

							}


							else if (topMiddle == false) {

								x = 0;
								y = boardRadius * 2 / 3;

								Line x1(Point(x - 2, y - 2), Point(x + 2, y + 2));
								Line x2(Point(x - 2, y + 2), Point(x + 2, y - 2));

								cwin << x1 << x2;

								topMiddle = true;

								xTopHorizontalMoves++;
								xMiddleVerticalMoves++;

							}

						else if (topRight==false) {

							x = boardRadius * 2 / 3;
							y = boardRadius * 2 / 3;

							Line x1(Point(x - 2, y - 2), Point(x + 2, y + 2));
							Line x2(Point(x - 2, y + 2), Point(x + 2, y - 2));

							cwin << x1 << x2;

							topRight = true;

							xTopHorizontalMoves++;
							xRightVerticalMoves++;
							xBottomTopDiagonalMoves++;

						}

						else if (middleLeft==false) {

							x = -boardRadius * 2 / 3;
							y = 0;

							Line x1(Point(x - 2, y - 2), Point(x + 2, y + 2));
							Line x2(Point(x - 2, y + 2), Point(x + 2, y - 2));

							cwin << x1 << x2;

							middleLeft = true;

							xMiddleHorizontalMoves++;
							xLeftVerticalMoves++;

						}
				
						else if (middleRight==false){

							x = boardRadius * 2 / 3;
							y = 0;

							Line x1(Point(x - 2, y - 2), Point(x + 2, y + 2));
							Line x2(Point(x - 2, y + 2), Point(x + 2, y - 2));

							cwin << x1 << x2;

							middleRight = true;

							xMiddleHorizontalMoves++;
							xRightVerticalMoves++;

						}

						else if (bottomLeft==false) {

							x = -boardRadius * 2 / 3;
							y = -boardRadius * 2 / 3;

							Line x1(Point(x - 2, y - 2), Point(x + 2, y + 2));
							Line x2(Point(x - 2, y + 2), Point(x + 2, y - 2));

							cwin << x1 << x2;

							bottomLeft = true;

							xBottomHorizontalMoves++;
							xLeftVerticalMoves++;
							xBottomTopDiagonalMoves++;

						}

						else if (bottomMiddle==false){

							x = 0;
							y = -boardRadius * 2 / 3;

							Line x1(Point(x - 2, y - 2), Point(x + 2, y + 2));
							Line x2(Point(x - 2, y + 2), Point(x + 2, y - 2));

							cwin << x1 << x2;

							bottomMiddle = true;

							xBottomHorizontalMoves++;
							xMiddleVerticalMoves++;

						}

						else if (bottomRight==false){

							x = boardRadius * 2 / 3;
							y = -boardRadius * 2 / 3;

							Line x1(Point(x - 2, y - 2), Point(x + 2, y + 2));
							Line x2(Point(x - 2, y + 2), Point(x + 2, y - 2));

							cwin << x1 << x2;

							bottomRight = true;

							xBottomHorizontalMoves++;
							xRightVerticalMoves++;
							xTopBottomDiagonalMoves++;
						}

				}

			/*This function alternates whose turn it is*/
				oTurn = !oTurn;
			
		}


	/*The following if statements draw a line if there were three moves
	in a row, column, or diagonal by either player.*/

		if (oTopHorizontalMoves == 3 ||xTopHorizontalMoves==3){
			cwin << Line(Point(-boardRadius, boardRadius*2/3), Point(boardRadius, boardRadius*2/3));
		}

		else if (oMiddleHorizontalMoves == 3||xMiddleHorizontalMoves==3){
			cwin << Line(Point(-boardRadius, 0), Point(boardRadius, 0));
		}
		else if (oBottomHorizontalMoves == 3||xBottomHorizontalMoves==3){
			cwin << Line(Point(-boardRadius, -boardRadius*2/3), Point(boardRadius, -boardRadius*2/3));
		}
		else if (oLeftVerticalMoves == 3||xLeftVerticalMoves==3){
			cwin << Line(Point(-boardRadius * 2/3, boardRadius), Point(-boardRadius * 2 / 3, -boardRadius));
		}
		else if (oMiddleVerticalMoves == 3||xMiddleVerticalMoves==3){
			cwin << Line(Point(0, boardRadius), Point(0, -boardRadius));
		}
		else if (oRightVerticalMoves == 3||xRightVerticalMoves==3){
			cwin << Line(Point(boardRadius * 2 / 3, boardRadius), Point(boardRadius * 2 / 3, -boardRadius));
		}
		else if (oTopBottomDiagonalMoves == 3||xTopBottomDiagonalMoves==3){
			cwin << Line(Point(-boardRadius, boardRadius), Point(boardRadius, -boardRadius));
		}
		else if (oBottomTopDiagonalMoves == 3||xBottomTopDiagonalMoves==3){
			cwin << Line(Point(-boardRadius, -boardRadius), Point(boardRadius, boardRadius));
		}


	/*The following if statements determine the winner to be whoever got 3 moves
	 in a row. If no one did, it is deemed a tie.*/

		if (oTopHorizontalMoves == 3 || oMiddleHorizontalMoves == 3 || oBottomHorizontalMoves == 3
			|| oLeftVerticalMoves == 3 || oMiddleVerticalMoves == 3 || oRightVerticalMoves == 3
			|| oTopBottomDiagonalMoves == 3 || oBottomTopDiagonalMoves == 3){

				cwin << Message(Point(-4, -9), "Game Over: The Guajolotes Win!");
		}

		else if (xTopHorizontalMoves == 3 || xMiddleHorizontalMoves == 3 || xBottomHorizontalMoves == 3
			|| xLeftVerticalMoves == 3 || xMiddleVerticalMoves == 3 || xRightVerticalMoves == 3
			|| xTopBottomDiagonalMoves == 3 || xBottomTopDiagonalMoves == 3){

				cwin << Message(Point(-3.5, -9), "Game Over: Player X Wins!");
		}

		else {
				cwin << Message(Point(-2.8, -9), "Game Over: It's a tie!");
		}

	
	/*This asks the user for input if they would like to play again.
	It clears the screen to a blank board if yes, and ends the program if not.*/

		string replay = cwin.get_string("Do you want to play again? Y/N");

		if (replay == "Y" || replay == "y" || replay == "Yes" || replay == "yes"){
			cwin.clear();
		}

		else if (replay == "N" || replay == "n" || replay == "N" || replay == "n"){
			playGame = false;
			cwin.clear();
			cwin << Message(Point(-1.5, 0), "Good game!");
		}

		else {
			bool reask = true;
			while (reask == true){
				string replay = cwin.get_string("Try again! Do you want to play again? Y/N");
				if (replay == "Y" || replay == "y" || replay == "Yes" || replay == "yes"){
					reask = false;
					cwin.clear();
				}

				else if (replay == "N" || replay == "n" || replay == "No" || replay == "no"){
					playGame = false;
					reask = false;
					cwin.clear();
					cwin << Message(Point(-1.5, 0), "Good game!");
				}

			}

		}

	}
	return 0;
}