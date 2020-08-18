#pragma once

constexpr int cCaveCount = 20;
constexpr int cPassPerCave = 3;
constexpr int cCaves[cCaveCount][cPassPerCave] = { { 1, 4, 7 }, { 0, 2, 9 }, { 1, 3, 11 }, { 2, 4, 13 },{ 0, 3, 5 },
	{ 4, 6, 14 }, { 5, 7, 16 }, { 0, 6, 8 }, { 7, 9, 17 }, { 1, 8, 10 },
	{ 9, 11, 18 }, { 2, 10, 12 }, { 11, 13, 19 }, { 3, 12, 14 }, { 5, 13, 15 },
	{ 14, 16, 19 }, { 6, 15, 17 }, { 8, 16, 18 }, { 10, 17, 19 }, { 12, 15, 18 } };
constexpr int cPassgaes = 0;