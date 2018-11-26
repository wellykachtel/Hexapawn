#include "controller.h"
#include <iostream>

using namespace hexapawn;
using namespace ge211;


namespace hexapawn {

    Controller::Controller(int m)
        :model_(m, m)
        , view_(model_)
        , mouse_column_(-1)
        , mouse_row_(-1)
        , selected_column_(-1)
        , selected_row_(-1)
    { }

    void Controller::draw(Sprite_set& set) {
        view_.draw(set, selected_column_, selected_row_, mouse_column_, mouse_row_);
    }

    void Controller::on_mouse_move(Position screen_pos) {
        mouse_column_ = view_.screen_to_board(screen_pos).x;
        mouse_row_ = view_.screen_to_board(screen_pos).y;
    }

    Dimensions Controller::initial_window_dimensions() const {
        return view_.screen_dimensions();
    }

    std::string Controller::initial_window_title() const {
        return "Noah and Kelly's Hexapawn";
    }

    void Controller::on_mouse_down(Mouse_button btn, Position screen_posn) {
        Player turn = model_.get_turn();
        if (model_.get_turn() == Player::neither) return;
        if (btn != Mouse_button::left) return;

        int col_no = view_.screen_to_board(screen_posn).x;
        int row_no = view_.screen_to_board(screen_posn).y;

        // if (!model_.is_good_spot(col_no, row_no, 0, 0)) return;
        if(model_.get_space(col_no, row_no) == turn) {

            selected_column_ = col_no;
            selected_row_ = row_no;
        } else if(model_.is_good_spot(selected_column_, selected_row_, col_no, row_no)) {
            std::cout << model_.is_good_spot(selected_column_, selected_row_, col_no, row_no)<< std::endl;
            model_.move_pawn(selected_column_, selected_row_, col_no, row_no);
        }

        //add last line
    }
}