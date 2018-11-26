#include "model.h"
#include <iostream>
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

    Model::Model(int c, int r)
        : c_(c), r_(r)
    {
        std::vector<Player> column;
        while(column.size() < c) {
            if(column.size() == 0) {
                column.push_back(Player::black);
            } else if(column.size() == c - 1) {
                column.push_back(Player::white);
            } else {
                column.push_back(Player::neither);
            }

        }

        while(grid_.size() < r) {
            grid_.push_back(column);
        }

    }

    void Model::move_pawn(int prev_col, int prev_row, int new_col, int new_row) {
        if (turn_ == Player::neither)
            throw ge211::Client_logic_error("move_pawn: game is over");

        if(get_space(prev_col, prev_row) != turn_) return;

        grid_[new_col][new_row] = turn_;
        grid_[prev_col][prev_row] = Player::neither;

        update_winner_and_turn_(new_row);

    }

    void Model::update_winner_and_turn_(int row_no) {
        if(!more_moves()) {
            winner_ = turn_;
        } else if(turn_ == Player::white && row_no == 0) {
            winner_ = turn_;
        } else if(turn_ == Player::black && row_no == r_ - 1) {
            winner_ = turn_;
        } else {
            turn_ = other_player(turn_);
            return;
        }

        turn_ = Player::neither;
    }


    bool Model::is_good_spot(int prev_col, int prev_row, int new_col, int new_row) const {
        if(new_col < 0 || new_col > c_) return false;
        if(new_row < 0 || new_row > r_) return false;
        Player player = turn_;
        Player new_space = get_space(new_col, new_row); //whether it is black, white, or neither

        if (player == Player::black) {
            if (new_row == prev_row + 1) {
                if(prev_col == new_col && new_space == Player::neither) {
                    return true;
                }
                if((new_col == prev_col + 1 || new_col == prev_col - 1) && new_space == Player::white) {
                    return true;
                }
            } else return false;
        } else if (player == Player::white) {
            if (new_row == prev_row - 1) {
                if(prev_col == new_col && new_space == Player::neither) {
                    return true;
                }
                if((new_col == prev_col + 1 || new_col == prev_col - 1) && new_space == Player::black) {
                    return true;
                }

            } else return false;
        } else return false;

        return false;

    }

    Player Model::get_space(int col_no, int row_no) const {
        return grid_[col_no][row_no];
    }

    bool Model::more_moves() {

        bool result = false;

        for(int col = 0; col < c_; ++col) {
            for (int row = 0; row < r_; ++row) {
                Player player = grid_[col][row];
                if (player == Player::neither) continue;
               /* result = result || (is_good_spot(col, row, col + 1, row)     ||
                                   is_good_spot(col, row, col, row + 1)     ||
                                   is_good_spot(col, row, col - 1, row)     ||
                                   is_good_spot(col, row, col, row - 1)     ||
                                   is_good_spot(col, row, col + 1, row + 1) ||
                                   is_good_spot(col, row, col - 1, row - 1) ||
                                   is_good_spot(col, row, col - 1, row + 1) ||
                                   is_good_spot(col, row, col + 1, row - 1));*/

                /*std::cout << "grid_[" << col << "][" << row << "] = " << is_good_spot(col, row, col + 1, row) << std::endl;
                std::cout << "grid_[" << col << "][" << row << "] = " << is_good_spot(col, row, col, row + 1)  << std::endl;
                std::cout << "grid_[" << col << "][" << row << "] = " << is_good_spot(col, row, col - 1, row) << std::endl;
                std::cout << "grid_[" << col << "][" << row << "] = " << is_good_spot(col, row, col, row - 1) << std::endl;
                std::cout << "grid_[" << col << "][" << row << "] = " << is_good_spot(col, row, col + 1, row + 1) << std::endl;
                std::cout << "grid_[" << col << "][" << row << "] = " << is_good_spot(col, row, col - 1, row - 1) << std::endl;
                std::cout << "grid_[" << col << "][" << row << "] = " << is_good_spot(col, row, col - 1, row + 1) << std::endl;
                std::cout << "grid_[" << col << "][" << row << "] = " << is_good_spot(col, row, col + 1, row - 1) << std::endl;
                std::cout << "****************************************************" << std::endl;*/
            }
        }

        std::cout << result << std::endl;
        return result;
    }
}