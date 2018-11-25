#pragma once

#include "model.h"
#include <ge211.h>

namespace hexapawn {

    ge211::Color const white_square_color = ge211::Color::white();
    ge211::Color const black_square_color = ge211::Color::black();
    ge211::Dimensions const square_dim = {400,400};


    class View
    {
    public:
        explicit View(Model const&);
        void draw(ge211::Sprite_set&, int mouse_row, int mouse_col) const;
        ge211::Dimensions screen_dimensions() const;
        ge211::Position board_to_screen(ge211::Position) const;
        ge211::Position screen_to_board(ge211::Position) const;


    private:
        Model const& model_;

        // a token when it is just on the board
       // ge211::Image_sprite const white_token_{"whitepawn.png"};
       // ge211::Image_sprite const black_token_{"blackpawn.png"};

        //a token when it is selected to be moved
       // ge211::Image_sprite const select_white_token_{"whitepawn_selected.png"};
       // ge211::Image_sprite const select_black_token_{"black_pawn_selected.png"};

        ge211::Rectangle_sprite const white_square_{square_dim, white_square_color};
        ge211::Rectangle_sprite const black_square_{square_dim, black_square_color};
    };
}