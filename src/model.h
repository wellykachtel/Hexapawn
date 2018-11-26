#pragma once

#include <ge211.h>
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

        //const std::vector<Player>& get_column(int col_no) const;
        void move_pawn(int, int, int, int);
        bool is_good_spot(int, int, int, int) const;
        Player get_turn() const { return turn_; };
        Player get_winner() const { return winner_; };
        Player get_space(int, int) const;
        bool more_moves();

    private:

        //m x n are the dimensions of the board (always a square)
        //m is the amount of pawns per player
        int c_;
        int r_;

        Player turn_ = Player::white;
        Player winner_ = Player::neither;

        //the board
        std::vector<std::vector<Player>> grid_;

        void update_winner_and_turn_(int row_no);

    };

}