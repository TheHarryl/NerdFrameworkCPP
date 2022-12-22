#include "pacman.h"
#include "PaletteTileBatch.h"
#include "PaletteImage.h"
#include "Interface.h"
#include "Grid2.h"
#include <vector>
#include "Math.h"
#include <iostream>
#include "GameState.h"

void launch() {
	const uint32_t w = Color4::white.toInteger();
	PaletteImage zero(8, 8, std::vector<uint8_t>{
		0,0,0,1,1,1,0,0,
		0,0,1,0,0,1,1,0,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,0,0,1,0,
		0,0,0,1,1,1,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage one(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,1,0,0,
		0,0,0,1,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage two(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,1,0,
		0,1,1,0,0,0,1,1,
		0,0,0,0,0,1,1,1,
		0,0,0,1,1,1,1,0,
		0,0,1,1,1,1,0,0,
		0,1,1,1,0,0,0,0,
		0,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage three(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,1,1,
		0,0,0,0,0,1,1,0,
		0,0,0,0,1,1,0,0,
		0,0,0,1,1,1,1,0,
		0,0,0,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage four(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,1,1,0,
		0,0,0,1,1,1,1,0,
		0,0,1,1,0,1,1,0,
		0,1,1,0,0,1,1,0,
		0,1,1,1,1,1,1,1,
		0,0,0,0,0,1,1,0,
		0,0,0,0,0,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage five(8, 8, std::vector<uint8_t>{
		0,1,1,1,1,1,1,0,
		0,1,1,0,0,0,0,0,
		0,1,1,1,1,1,1,0,
		0,0,0,0,0,0,1,1,
		0,0,0,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage six(8, 8, std::vector<uint8_t>{
		0,0,0,1,1,1,1,0,
		0,0,1,1,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,1,1,1,1,1,1,0,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage seven(8, 8, std::vector<uint8_t>{
		0,1,1,1,1,1,1,1,
		0,1,1,0,0,0,1,1,
		0,0,0,0,0,1,1,0,
		0,0,0,0,1,1,0,0,
		0,0,0,1,1,0,0,0,
		0,0,0,1,1,0,0,0,
		0,0,0,1,1,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage eight(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,0,0,
		0,1,1,0,0,0,1,0,
		0,1,1,1,0,0,1,0,
		0,0,1,1,1,1,0,0,
		0,1,0,0,1,1,1,1,
		0,1,0,0,0,0,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage nine(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,1,0,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,1,1,1,1,
		0,0,0,0,0,0,1,1,
		0,0,0,0,0,1,1,0,
		0,0,1,1,1,1,0,0,
		0,0,0,0,0,0,0,0,
	});

	PaletteImage A(8, 8, std::vector<uint8_t>{
		0,0,0,1,1,1,0,0,
		0,0,1,1,0,1,1,0,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage B(8, 8, std::vector<uint8_t>{
		0,1,1,1,1,1,1,0,
		0,1,0,0,0,0,1,1,
		0,1,0,0,0,0,1,1,
		0,1,1,1,1,1,1,0,
		0,1,0,0,0,0,1,1,
		0,1,0,0,0,0,1,1,
		0,1,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage C(8, 8, std::vector<uint8_t>{
		0,0,0,1,1,1,1,0,
		0,0,1,1,0,0,1,1,
		0,1,1,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,0,1,1,0,0,1,1,
		0,0,0,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage D(8, 8, std::vector<uint8_t>{
		0,1,1,1,1,1,0,0,
		0,1,1,0,0,1,1,0,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,1,1,0,
		0,1,1,1,1,1,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage E(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,1,1,
		0,0,1,1,0,0,0,0,
		0,0,1,1,0,0,0,0,
		0,0,1,1,1,1,1,0,
		0,0,1,1,0,0,0,0,
		0,0,1,1,0,0,0,0,
		0,0,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage F(8, 8, std::vector<uint8_t>{
		0,1,1,1,1,1,1,1,
		0,1,1,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,1,1,1,1,1,1,0,
		0,1,1,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage G(8, 8, std::vector<uint8_t>{
		0,0,0,1,1,1,1,1,
		0,0,1,1,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,1,1,0,0,1,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,0,0,1,1,
		0,0,0,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage H(8, 8, std::vector<uint8_t>{
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage I(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,1,1,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage J(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,1,1,
		0,0,0,0,0,0,1,1,
		0,0,0,0,0,0,1,1,
		0,0,0,0,0,0,1,1,
		0,0,0,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage K(8, 8, std::vector<uint8_t>{
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,1,1,0,
		0,1,1,0,1,1,0,0,
		0,1,1,1,1,0,0,0,
		0,1,1,1,1,1,0,0,
		0,1,1,0,1,1,1,0,
		0,1,1,0,0,1,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage L(8, 8, std::vector<uint8_t>{
		0,0,1,1,0,0,0,0,
		0,0,1,1,0,0,0,0,
		0,0,1,1,0,0,0,0,
		0,0,1,1,0,0,0,0,
		0,0,1,1,0,0,0,0,
		0,0,1,1,0,0,0,0,
		0,0,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage M(8, 8, std::vector<uint8_t>{
		0,1,1,0,0,0,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,0,1,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage N(8, 8, std::vector<uint8_t>{
		0,1,1,0,0,0,1,1,
		0,1,1,1,0,0,1,1,
		0,1,1,1,1,0,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,0,1,1,1,1,
		0,1,1,0,0,1,1,1,
		0,1,1,0,0,0,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage O(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,1,0,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage P(8, 8, std::vector<uint8_t>{
		0,1,1,1,1,1,1,0,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,1,1,1,1,0,
		0,1,1,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage Q(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,1,0,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,1,1,1,1,
		0,1,1,0,0,1,1,0,
		0,0,1,1,1,1,0,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage R(8, 8, std::vector<uint8_t>{
		0,1,1,1,1,1,1,0,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,1,1,1,
		0,1,1,1,1,1,0,0,
		0,1,1,0,1,1,1,0,
		0,1,1,0,0,1,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage S(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,0,0,
		0,1,1,0,0,1,1,0,
		0,1,1,0,0,0,0,0,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage T(8, 8, std::vector<uint8_t>{
		0,0,1,1,1,1,1,1,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage U(8, 8, std::vector<uint8_t>{
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage V(8, 8, std::vector<uint8_t>{
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,1,0,1,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,1,1,1,0,0,
		0,0,0,0,1,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage W(8, 8, std::vector<uint8_t>{
		0,1,1,0,0,0,1,1,
		0,1,1,0,0,0,1,1,
		0,1,1,0,1,0,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,0,0,0,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage X(8, 8, std::vector<uint8_t>{
		0,1,1,0,0,0,1,1,
		0,1,1,1,0,1,1,1,
		0,0,1,1,1,1,1,0,
		0,0,0,1,1,1,0,0,
		0,0,1,1,1,1,1,0,
		0,1,1,1,0,1,1,1,
		0,1,1,0,0,0,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage Y(8, 8, std::vector<uint8_t>{
		0,0,1,1,0,0,1,1,
		0,0,1,1,0,0,1,1,
		0,0,1,1,0,0,1,1,
		0,0,0,1,1,1,1,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,1,1,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage Z(8, 8, std::vector<uint8_t>{
		0,1,1,1,1,1,1,1,
		0,0,0,0,0,1,1,1,
		0,0,0,0,1,1,1,0,
		0,0,0,1,1,1,0,0,
		0,0,1,1,1,0,0,0,
		0,1,1,1,0,0,0,0,
		0,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage period(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage comma(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,0,1,0,0,0,0,0,
	});
	PaletteImage exclamation(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,1,1,0,
		0,0,0,0,1,1,1,0,
		0,0,0,1,1,1,0,0,
		0,0,0,1,1,0,0,0,
		0,0,0,1,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage quote(8, 8, std::vector<uint8_t>{
		0,0,1,1,0,1,1,0,
		0,0,1,1,0,1,1,0,
		0,0,0,1,0,0,1,0,
		0,0,1,0,0,1,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});

	const uint32_t f = Color4(255, 185, 175).toInteger();
	PaletteImage lil_food(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,3,3,0,0,0,
		0,0,0,3,3,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage mid_food(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,3,3,0,0,0,
		0,0,3,3,3,3,0,0,
		0,0,3,3,3,3,0,0,
		0,0,0,3,3,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage big_food(8, 8, std::vector<uint8_t>{
		0,0,3,3,3,3,0,0,
		0,3,3,3,3,3,3,0,
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,
		0,3,3,3,3,3,3,0,
		0,0,3,3,3,3,0,0,
	});

	const uint32_t b = Color4(33, 33, 255).toInteger();
	PaletteImage wall_fill(8, 8, std::vector<uint8_t>{
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
	});
	PaletteImage reg_1(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,
		0,0,0,0,0,1,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
	});
	PaletteImage reg_2(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
	});
	PaletteImage reg_3(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		1,1,0,0,0,0,0,0,
		2,2,1,0,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
	});
	PaletteImage reg_4(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
	});
	PaletteImage reg_5(8, 8, std::vector<uint8_t>{
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
	});
	PaletteImage reg_6(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,0,1,2,2,
		0,0,0,0,0,0,1,1,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage reg_7(8, 8, std::vector<uint8_t>{
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage reg_8(8, 8, std::vector<uint8_t>{
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,1,0,0,0,0,0,
		1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	
	PaletteImage big_1(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,1,1,1,
		0,0,1,1,2,2,2,2,
		0,1,2,2,2,2,2,2,
		0,1,2,2,2,1,1,1,
		1,2,2,2,1,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
	});
	PaletteImage big_2(8, 8, std::vector<uint8_t>{
		1,1,1,1,1,1,1,1,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage big_3(8, 8, std::vector<uint8_t>{
		1,1,1,1,0,0,0,0,
		2,2,2,2,1,1,0,0,
		2,2,2,2,2,2,1,0,
		1,1,1,2,2,2,1,0,
		0,0,0,1,2,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
	});
	PaletteImage big_4(8, 8, std::vector<uint8_t>{
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
	});
	PaletteImage big_5(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
	});
	PaletteImage big_6(8, 8, std::vector<uint8_t>{
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,2,1,0,0,0,
		0,1,2,2,2,1,1,1,
		0,1,2,2,2,2,2,2,
		0,0,1,1,2,2,2,2,
		0,0,0,0,1,1,1,1,
	});
	PaletteImage big_7(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		1,1,1,1,1,1,1,1,
	});
	PaletteImage big_8(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,1,2,2,2,1,
		1,1,1,2,2,2,1,0,
		2,2,2,2,2,2,1,0,
		2,2,2,2,1,1,0,0,
		1,1,1,1,0,0,0,0,
	});

	const uint32_t p = Color4(255, 185, 255).toInteger();
	PaletteImage sqr_1(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,1,1,1,1,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,1,
	});
	PaletteImage sqr_2(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage sqr_3(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		1,1,1,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
	});
	PaletteImage sqr_6(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,1,1,1,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	PaletteImage sqr_8(8, 8, std::vector<uint8_t>{
		1,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		1,1,1,1,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	});
	
	PaletteImage unq_1(8, 8, std::vector<uint8_t>{
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,2,1,0,0,0,
		1,2,2,2,2,1,1,1,
		1,2,2,2,2,2,2,2,
		1,2,2,2,2,2,2,2,
		1,2,2,2,2,2,2,2,
	});
	PaletteImage unq_2(8, 8, std::vector<uint8_t>{
		1,2,2,2,2,2,2,2,
		1,2,2,2,2,2,2,2,
		1,2,2,2,2,2,2,2,
		1,2,2,2,2,1,1,1,
		1,2,2,2,1,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
		1,2,2,1,0,0,0,0,
	});
	PaletteImage unq_3(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,1,2,2,2,1,
		1,1,1,2,2,2,2,1,
		2,2,2,2,2,2,2,1,
		2,2,2,2,2,2,2,1,
		2,2,2,2,2,2,2,1,
	});
	PaletteImage unq_4(8, 8, std::vector<uint8_t>{
		2,2,2,2,2,2,2,1,
		2,2,2,2,2,2,2,1,
		2,2,2,2,2,2,2,1,
		1,1,1,2,2,2,2,1,
		0,0,0,1,2,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
		0,0,0,0,1,2,2,1,
	});
	PaletteImage unq_5(8, 8, std::vector<uint8_t>{
		1,1,1,1,1,1,1,1,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		1,1,1,2,2,2,2,2,
		0,0,0,1,2,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
	});
	PaletteImage unq_6(8, 8, std::vector<uint8_t>{
		1,1,1,1,1,1,1,1,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,1,1,1,
		2,2,2,2,1,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
	});
	PaletteImage unq_7(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		2,2,2,2,2,2,2,1,
		2,2,2,2,2,2,2,1,
		1,1,1,1,1,1,1,1,
	});
	PaletteImage unq_8(8, 8, std::vector<uint8_t>{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		1,2,2,2,2,2,2,2,
		1,2,2,2,2,2,2,2,
		1,1,1,1,1,1,1,1,
	});

	PaletteImage cnv_1(8, 8, std::vector<uint8_t>{
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,1,1,1,
		2,2,2,2,1,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
	});
	PaletteImage cnv_2(8, 8, std::vector<uint8_t>{
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		1,1,1,2,2,2,2,2,
		0,0,0,1,2,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
	});
	PaletteImage cnv_3(8, 8, std::vector<uint8_t>{
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,1,0,0,0,0,
		2,2,2,2,1,0,0,0,
		2,2,2,2,2,1,1,1,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
	});
	PaletteImage cnv_4(8, 8, std::vector<uint8_t>{
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,0,1,2,2,2,
		0,0,0,1,2,2,2,2,
		1,1,1,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,
	});

	Grid2<uint8_t> board(28, 36, {
		40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,
		40,40,40,40,40,00,00,40,40,40,40,40,40,40,40,00,00,40,40,40,40,40,40,40,40,40,40,40,
		40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,
		21,22,22,22,22,22,22,22,22,22,22,22,22,55,56,22,22,22,22,22,22,22,22,22,22,22,22,23,
		24,10,10,10,10,10,10,10,10,10,10,10,10,14,15,10,10,10,10,10,10,10,10,10,10,10,10,25,
		24,10,11,12,12,13,10,11,12,12,12,13,10,14,15,10,11,12,12,12,13,10,11,12,12,13,10,25,
		24,30,14,50,50,15,10,14,50,50,50,15,10,14,15,10,14,50,50,50,15,10,14,50,50,15,30,25,
		24,10,16,17,17,18,10,16,17,17,17,18,10,16,18,10,16,17,17,17,18,10,16,17,17,18,10,25,
		24,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,25,
		24,10,11,12,12,13,10,11,13,10,11,12,12,12,12,12,12,13,10,11,13,10,11,12,12,13,10,25,
		24,10,16,17,17,18,10,14,15,10,16,17,17,29,19,17,17,18,10,14,15,10,16,17,17,18,10,25,
		24,10,10,10,10,10,10,14,15,10,10,10,10,14,15,10,10,10,10,14,15,10,10,10,10,10,10,25,
		26,27,27,27,27,13,10,14,39,12,12,13,40,14,15,40,11,12,12,49,15,10,11,27,27,27,27,28,
		40,40,40,40,40,24,10,14,19,17,17,18,40,16,18,40,16,17,17,29,15,10,25,40,40,40,40,40,
		40,40,40,40,40,24,10,14,15,40,40,40,40,40,40,40,40,40,40,14,15,10,25,40,40,40,40,40,
		40,40,40,40,40,24,10,14,15,40,31,27,57,35,35,58,27,37,40,14,15,10,25,40,40,40,40,40,
		22,22,22,22,22,18,10,16,18,40,25,40,40,40,40,40,40,24,40,16,18,10,16,22,22,22,22,22,
		40,40,40,40,40,40,10,40,40,40,25,40,40,40,40,40,40,24,40,40,40,10,40,40,40,40,40,40,
		27,27,27,27,27,13,10,11,13,40,25,40,40,40,40,40,40,24,40,11,13,10,11,27,27,27,27,27,
		40,40,40,40,40,24,10,14,15,40,36,22,22,22,22,22,22,38,40,14,15,10,25,40,40,40,40,40,
		40,40,40,40,40,24,10,14,15,40,40,40,40,40,40,40,40,40,40,14,15,10,25,40,40,40,40,40,
		40,40,40,40,40,24,10,14,15,40,11,12,12,12,12,12,12,13,40,14,15,10,25,40,40,40,40,40,
		21,22,22,22,22,18,10,16,18,40,16,17,17,29,19,17,17,18,40,16,18,10,16,22,22,22,22,23,
		24,10,10,10,10,10,10,10,10,10,10,10,10,14,15,10,10,10,10,10,10,10,10,10,10,10,10,25,
		24,10,11,12,12,13,10,11,12,12,12,13,10,14,15,10,11,12,12,12,13,10,11,12,12,13,10,25,
		24,10,16,17,29,15,10,16,17,17,17,18,10,16,18,10,16,17,17,17,18,10,14,19,17,18,10,25,
		24,30,10,10,14,15,10,10,10,10,10,10,10,40,40,10,10,10,10,10,10,10,14,15,10,10,30,25,
		51,12,13,10,14,15,10,11,13,10,11,12,12,12,12,12,12,13,10,11,13,10,14,15,10,11,12,53,
		52,17,18,10,16,18,10,14,15,10,16,17,17,29,19,17,17,18,10,14,15,10,16,18,10,16,17,54,
		24,10,10,10,10,10,10,14,15,10,10,10,10,14,15,10,10,10,10,14,15,10,10,10,10,10,10,25,
		24,10,11,12,12,12,12,49,39,12,12,13,10,14,15,10,11,12,12,49,39,12,12,12,12,13,10,25,
		24,10,16,17,17,17,17,17,17,17,17,18,10,16,18,10,16,17,17,17,17,17,17,17,17,18,10,25,
		24,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,25,
		26,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,28,
		40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,
		40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,
	});
	Grid2<uint8_t> paletteBoard(28, 36, {
		02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,
		02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,
		02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,03,03,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,
		02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,
		02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,02,
	});
	//std::fill(paletteBoard.data() + 28*2, paletteBoard.data() + paletteBoard.size(), 4);
	PaletteTileBatch* tileBatch;

	std::map<uint8_t, PaletteImage> tileTypes {
		{ 0, std::move(zero) },
		{ 1, std::move(one) },
		{ 2, std::move(two) },
		{ 3, std::move(three) },
		{ 4, std::move(four) },
		{ 5, std::move(five) },
		{ 6, std::move(six) },
		{ 7, std::move(seven) },
		{ 8, std::move(eight) },
		{ 9, std::move(nine) },

		{ 'A', std::move(A) },
		{ 'B', std::move(B) },
		{ 'C', std::move(C) },
		{ 'D', std::move(D) },
		{ 'E', std::move(E) },
		{ 'F', std::move(F) },
		{ 'G', std::move(G) },
		{ 'H', std::move(H) },
		{ 'I', std::move(I) },
		{ 'J', std::move(J) },
		{ 'K', std::move(K) },
		{ 'L', std::move(L) },
		{ 'M', std::move(M) },
		{ 'N', std::move(N) },
		{ 'O', std::move(O) },
		{ 'P', std::move(P) },
		{ 'Q', std::move(Q) },
		{ 'R', std::move(R) },
		{ 'S', std::move(S) },
		{ 'T', std::move(T) },
		{ 'U', std::move(U) },
		{ 'V', std::move(V) },
		{ 'W', std::move(W) },
		{ 'X', std::move(X) },
		{ 'Y', std::move(Y) },
		{ 'Z', std::move(Z) },
		{ ' ', PaletteImage::none },
		{ '.', std::move(period) },
		{ ',', std::move(comma) },
		{ '!', std::move(exclamation) },
		{ '"', std::move(quote) },

		{ 11, std::move(reg_1) },
		{ 12, std::move(reg_2) },
		{ 13, std::move(reg_3) },
		{ 14, std::move(reg_4) },
		{ 15, std::move(reg_5) },
		{ 16, std::move(reg_6) },
		{ 17, std::move(reg_7) },
		{ 18, std::move(reg_8) },

		{ 21, std::move(big_1) },
		{ 22, std::move(big_2) },
		{ 23, std::move(big_3) },
		{ 24, std::move(big_4) },
		{ 25, std::move(big_5) },
		{ 26, std::move(big_6) },
		{ 27, std::move(big_7) },
		{ 28, std::move(big_8) },

		{ 31, std::move(sqr_1) },
		{ 35, std::move(sqr_2) },
		{ 37, std::move(sqr_3) },
		{ 36, std::move(sqr_6) },
		{ 38, std::move(sqr_8) },

		{ 51, std::move(unq_1) },
		{ 52, std::move(unq_2) },
		{ 53, std::move(unq_3) },
		{ 54, std::move(unq_4) },
		{ 55, std::move(unq_5) },
		{ 56, std::move(unq_6) },
		{ 57, std::move(unq_7) },
		{ 58, std::move(unq_8) },

		{ 19, std::move(cnv_1) },
		{ 29, std::move(cnv_2) },
		{ 39, std::move(cnv_3) },
		{ 49, std::move(cnv_4) },

		{ 10, std::move(lil_food) },
		{ 20, std::move(mid_food) },
		{ 30, std::move(big_food) },
		{ 40, PaletteImage::none },
		{ 50, std::move(wall_fill) }
	};
	Color4 black(0, 0, 0);
	Color4 red(252, 0, 0);
	Color4 brown(216, 144, 85);
	Color4 pink(252, 180, 255);
	Color4 cyan(0, 252, 255);
	Color4 blue(72, 180, 255);
	Color4 orange(252, 180, 85);
	Color4 yellow(252, 252, 0);
	Color4 indigo(36, 36, 255);
	Color4 green(0, 252, 0);
	Color4 teal(72, 180, 170);
	Color4 salmon(252, 180, 170);
	Color4 white(252, 252, 255);
	std::map<uint8_t, Palette<Color4>> palettes{
		{ 0, { { Color4::none, black, black, black } } },
		{ 1, { { Color4::none, indigo, black, salmon } } },
		{ 2, { { Color4::none, white, brown, red } } },
		{ 3, { { Color4::none, yellow, pink, teal } } },
		{ 4, { { Color4::none, black, black, black } } },
		{ 5, { { Color4::none, red, indigo, white } } },
		{ 6, { { Color4::none, teal, indigo, white } } },
		{ 7, { { Color4::none, yellow, red, indigo } } },
		{ 8, { { Color4::none, salmon, indigo, green } } },
		{ 9, { { Color4::none, brown, green, orange } } },
		{ 10, { { Color4::none, black, indigo, white } } },
		{ 11, { { Color4::none, red, salmon, white } } },
	};

	std::vector<size_t> POWER_PELLET_INDICES;
	{
		uint8_t* data = board.data();
		for (size_t i = 0; i < board.size(); i++)
			if (data[i] == 30)
				POWER_PELLET_INDICES.push_back(i);
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{

		Interface interface(SDL_CreateWindow("Pac-Man", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 28 * 16, 36 * 16, 0), [&](Interface& interface, SDL_Renderer* renderer)-> void {
			tileBatch = new PaletteTileBatch(renderer);

			tileBatch->setGrid(std::move(board));
			tileBatch->setTileTypes(std::move(tileTypes));
			tileBatch->setPaletteGrid(std::move(paletteBoard));
			tileBatch->setPaletteTypes(std::move(palettes));

			std::string text = "   \1UP   HIGH SCORE";
			std::move(text.data(), text.data() + text.length(), tileBatch->gridData());

			GameState::getInstance().tileBatch = tileBatch;
		});
		interface.onDraw = [&](Interface& interface, Image4& screen, const Rect2<double>& bounds) -> void {
			tileBatch->draw(screen, Rect2<double>{0.0, 0.0, 16, 16});
		};
		interface.onDrawSDL = [&](Interface& interface, SDL_Renderer* renderer, const Rect2<double>& bounds) -> void {
			tileBatch->draw(renderer, Rect2<double>{0.0, 0.0, 16, 16});
		};
		uint8_t* paletteData = tileBatch->paletteGridData();
		interface.onUpdate = [&](Interface& interface, double delta) -> void {
			if (Math::dmod(interface.secondsElapsed(), 0.5) >= 0.25 && paletteData[3] == 2)
				std::fill(paletteData + 3, paletteData + 6, 10);
			else if (Math::dmod(interface.secondsElapsed(), 0.5) < 0.25 && paletteData[3] == 10)
				std::fill(paletteData + 3, paletteData + 6, 2);
			for (size_t i : POWER_PELLET_INDICES) {
				if (Math::dmod(interface.secondsElapsed(), 1.0 / 3.0) >= 1.0 / 6.0 && paletteData[i] == 1)
					paletteData[i] = 4;
				else if (Math::dmod(interface.secondsElapsed(), 1.0 / 3.0) < 1.0 / 6.0 && paletteData[i] == 4)
					paletteData[i] = 1;
			}
		};

		if (interface.window == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			SDL_Quit();
			return;
		}
		else
		{
			bool running = true;
			while (running) {
				SDL_Event ev;
				while (SDL_PollEvent(&ev))
				{
					if ((SDL_QUIT == ev.type) ||
						(SDL_KEYDOWN == ev.type && SDL_SCANCODE_ESCAPE == ev.key.keysym.scancode))
					{
						running = false;
						break;
					}
				}

				interface.update();
				interface.drawSDL();
			}
		}
		delete tileBatch;

	}
	SDL_Quit();
}