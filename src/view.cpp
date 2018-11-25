#include "view.h"
#include <iostream>

namespace hexapawn {
    View::View(const Model& model)
        : model_(model)
    { }

    void View::draw(ge211::Sprite_set& sprites, int mouse_row, int mouse_col) const {

        for(int col = 0; col < model_.m(); ++col) {
            for(int row = 0; row < model_.n(); ++row) {
                bool col_is_even = col%2 == 0;
                bool row_is_even = row%2 == 0;
                if(col_is_even && row_is_even) {
                    sprites.add_sprite(white_square_, {square_dim.width*col, square_dim.height*row}, 0);
                    std::cout << "white square at" << square_dim.width*col << " x " <<square_dim.height*row <<std::endl;
                } else {
                    sprites.add_sprite(black_square_, {square_dim.width*col, square_dim.height*row}, 0);
                    std::cout << "black square at" << square_dim.width*col << " x " <<square_dim.height*row <<std::endl;
                }
            }
        }
    }


    ge211::Position View::board_to_screen(ge211::Position board_pos) const
    {

        //use Sprite.dimensions to get dimensions of a sprite
        int x = 2 * square_dim.width * board_pos.x;
        int y = 2 * square_dim.height * (model_.n() - board_pos.y - 1);
        return {x, y};
    }

    ge211::Position View::screen_to_board(ge211::Position screen_pos) const
    {
        int col_no = screen_pos.x / (2 * square_dim.width);
        int row_no = model_.n() - screen_pos.y / (2 * square_dim.height) - 1;
        return {col_no, row_no};
    }

    ge211::Dimensions View::screen_dimensions() const {
        return {square_dim.width * model_.m(),
                square_dim.height * model_.n()};
    }

}