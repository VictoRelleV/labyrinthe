#include "clientAPI.h"

connectToServer( "172.105.76.1", 1234, "DONTMOVE") ;

/* ------------------------------------------------------------------------------
 * Wait for a Game, and retrieve its name and first data (array of the labyrinth
 *
 * Parameters:
 * - gameType: string (max 200 characters) type of the game we want to play (empty string for regular game)
 * - labyrinthName: string (max 50 characters), corresponds to the game name (filled by the function)
 * - sizeX, sizeY: sizes of the labyrinth
 *
 * gameType is a string like "GAME key1=value1 key2=value1 ..."
 * - It indicates the type of the game you want to plys
 *   it could be "TRAINING <BOT>" to play against bot <BOT>
 *   or "TOURNAMENT xxxx" to join the tournament xxxx
 *   or "" (empty string) to wait for an opponent (decided by the server)
 * - key=value pairs are used for options (each training player has its own options)
 *   invalid keys are ignored, invalid values leads to error
 *   the following options are common to every training player:
 *   - timeout: allows an define the timeout when training (in seconds)
 *   - 'seed': allows to set the seed of the random generator
 *   - 'start': allows to set who starts ('0' or '1')
 *
 * The bot name <BOT> could be:
 * - "PLAY_RANDOM" for a player that make random (but legal) moves
 * - "ASTAR" for a
 *
 *
 */
waitForLabyrinth( "TRAINING <DONTMOVE>", char* labyrinthName, int* sizeX, int* sizeY) ;
{
	char data[128];
	/* wait for a game */
	waitForGame( __FUNCTION__, gameType, labyrinthName, data);

	/* parse the data */
	sscanf( data, "%d %d", sizeX, sizeY);

	/* store the sizes, so that we can reuse them during getLabyrinth */
	nX = *sizeX;
	nY = *sizeY;
}

closeConnection() ;

echo "# Projet-Labyrinthe-" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/VictoRelleV/Projet-Labyrinthe-.git
git push -u origin main
