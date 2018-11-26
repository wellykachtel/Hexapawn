#pragma once

#include "model.h"
#include <ge211.h>

namespace hexapawn {

    ge211::Color const white_square_color = ge211::Color::white();
    ge211::Color const black_square_color = ge211::Color::black();
    ge211::Color const player_indicate_color = ge211::Color::medium_blue().lighten(0.3);

    ge211::Dimensions const square_dim = {150,150};
    int const margin_top = square_dim.height;
    int const margin_bottom = square_dim.height;



    class View
    {
    public:
        explicit View(Model const&);
        void draw(ge211::Sprite_set&, int, int, int, int) const;
        ge211::Dimensions screen_dimensions() const;
        ge211::Position board_to_screen(ge211::Position) const;
        ge211::Position screen_to_board(ge211::Position) const;


    private:
        Model const& model_;

        // a token when it is just on the board
        ge211::Image_sprite const white_token_{"whitepawn.png"};
        ge211::Image_sprite const black_token_{"blackpawn.png"};

        //a token when it is selected to be moved
        ge211::Image_sprite const select_white_token_{"whitepawn_selected.png"};
        ge211::Image_sprite const select_black_token_{"blackpawn_selected.png"};

        ge211::Image_sprite const possible_white_token_{"possible_whitepawn.png"};
        ge211::Image_sprite const possible_black_token_{"possible_blackpawn.png"};

        ge211::Font sans30{"sans.ttf", 30};
        ge211::Font sans20{"sans.ttf", 25};

        ge211::Text_sprite const title_{"Welcome to Hexapawn", sans30};
        ge211::Text_sprite const winner_1_title_{"Player 1 Wins!", sans30};
        ge211::Text_sprite const winner_2_title_{"Player 2 Wins!", sans30};
        ge211::Text_sprite const player_1_{"Player 1", sans20};
        ge211::Text_sprite const player_2_{"Player 2", sans20};

        ge211::Rectangle_sprite const player_1_turn{player_1_.dimensions(), player_indicate_color};
        ge211::Rectangle_sprite const player_2_turn{player_2_.dimensions(), player_indicate_color};


        ge211::Rectangle_sprite const white_square_{square_dim, white_square_color};
        ge211::Rectangle_sprite const black_square_{square_dim, black_square_color};
    };
}