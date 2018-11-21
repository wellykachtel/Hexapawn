#pragma once

#include <ge211.h>
#include <vector>

namespace hexpawn {

    enum class Player {
        white, black, neither
    };

/// Returns the other player, if given Player::first or Player::second;
/// throws ge211::Client_logic_error if given Player::neither.
    Player other_player(Player);

    class Model {
    public:
        explicit Model(int m = 3, int n = 3);
        int m() const { return m_; }
        int n() const { return n_; }

        //const std::vector<Player>& get_column(int col_no) const;
        void move_pawn(int, int, int, int);
        bool is_good_spot(int col_no, int row_no) const;
        Player get_turn() const { return turn_; };
        Player get_winner() const { return winner_; };

    private:

        //m x n are the dimensions of the board (always a square)
        //m is the amount of pawns per player
        int m_;
        int n_;

        Player turn_ = Player::white;
        Player winner_ = Player::neither;

        //the board
        std::vector<std::vector<Player>> grid_;

        Player get_space_(int, int);

        void update_winner_and_turn_(int col_no, int row_no);

        bool is_good_space_(int, int, int, int) const;
    };

}