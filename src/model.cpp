#include "model.h"
#include <ge211.h>

namespace hexapawn {

    Player other_player(Player p)
    {
        switch(p) {
            case Player::white: return Player::black;
            case Player::black: return Player::white;
            default:
                throw ge211::Client_logic_error("other_player: not a player");
        }
    }

    Model::Model(int m, int n)
        : m_(m), n_(n)
    {
        std::vector<Player> column;
        while(column.size() < n) {
            if(column.size() == 0) {
                column.push_back(Player::black);
            } else if(column.size() == n - 1) {
                column.push_back(Player::white);
            } else {
                column.push_back(Player::neither);
            }

        }

        while(grid_.size() < m) {
            grid_.push_back(column);
        }

    }

    void Model::move_pawn(int prev_row, int prev_col, int new_row, int new_col) {
        if (turn_ == Player::neither)
            throw ge211::Client_logic_error("place_token: game is over");

        if(get_space_(prev_row, prev_col) != turn_) return;

    }

    Player Model::get_space_(int row_no, int col_no) {
        return grid_.at(row_no).at(col_no);
    }

    void Model::update_winner_and_turn_(int col_no, int row_no) {
        return;
    }


    bool Model::is_good_spot(int prev_row, int prev_col, int new_row, int new_col) const {
        return true;
    }
}