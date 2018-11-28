#pragma once

#include <vector>

namespace hexapawn {

    enum class Player {
        white, black, neither
    };

/// Returns the other player, if given Player::first or Player::second;
/// throws ge211::Client_logic_error if given Player::neither.
    Player other_player(Player);

    class Model {
    public:
        explicit Model(int c = 3, int r = 3);
        int c() const { return c_; }
        int r() const { return r_; }

        //performs the move, of a pawn
        void move_pawn(int, int, int, int);

        //validates whether a move is valid for a given pawn
        bool is_good_spot(int, int, int, int) const;

        //black or white?
        Player get_turn() const { return turn_; };

        //returns a winner, if game is still being played, it's neither
        Player get_winner() const { return winner_; };

        //says whether a space is occupied by black, white, or neither
        Player get_space(int, int) const;

    private:

        //c x r are the dimensions of the board
        //c is the amount of pawns per player
        int c_;
        int r_;

        Player turn_ = Player::white;
        Player winner_ = Player::neither;

        // the board
        std::vector<std::vector<Player>> grid_;

        // called after every successful move to switch
        // players and determine if anyone has won
        void update_winner_and_turn_(int row_no);

        // does the player who's turn it is have any more valid moves
        bool more_moves();

    };

}