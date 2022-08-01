/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:46:16 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 16:46:17 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# ifdef __APPLE__
#  define A_KEY 0
#  define B_KEY 11
#  define C_KEY 8
#  define D_KEY 2
#  define E_KEY 14
#  define F_KEY 3
#  define G_KEY 5
#  define H_KEY 4
#  define I_KEY 34
#  define J_KEY 38
#  define K_KEY 40
#  define L_KEY 37
#  define M_KEY 46
#  define N_KEY 45
#  define O_KEY 31
#  define P_KEY 35
#  define Q_KEY 12
#  define R_KEY 15
#  define S_KEY 1
#  define T_KEY 17
#  define U_KEY 32
#  define V_KEY 9
#  define W_KEY 13
#  define X_KEY 7
#  define Y_KEY 16
#  define Z_KEY 6

#  define UP0_KEY 29
#  define UP1_KEY 18
#  define UP2_KEY 19
#  define UP3_KEY 20
#  define UP4_KEY 21
#  define UP5_KEY 23
#  define UP6_KEY 22
#  define UP7_KEY 26
#  define UP8_KEY 28
#  define UP9_KEY 25
#  define DOT_KEY 47
#  define MINUS_KEY 27
#  define COMA_KEY 43

#  define UP0_KEYA 29
#  define UP1_KEYA 18
#  define UP2_KEYA 19
#  define UP3_KEYA 20
#  define UP4_KEYA 21
#  define UP5_KEYA 23
#  define UP6_KEYA 22
#  define UP7_KEYA 26
#  define UP8_KEYA 28
#  define UP9_KEYA 25
#  define DOT_KEYA 47

#  define UP_KEY 126
#  define DOWN_KEY 125
#  define RIGHT_KEY 124
#  define LEFT_KEY 123

#  define ESCAPE 53
#  define ENTER 36
#  define CLOSE 17

#  define N1_KEY 83
#  define N2_KEY 84
#  define N3_KEY 85
#  define N4_KEY 86
#  define N5_KEY 87
#  define N6_KEY 88
#  define N7_KEY 89
#  define N8_KEY 91
#  define N9_KEY 92

#  define MAX_DEFX 2560
#  define MAX_DEFY 1440

#  define DEC 20
#  define APPLE 1

# else

#  define A_KEY 97
#  define B_KEY 98
#  define C_KEY 99
#  define D_KEY 100
#  define E_KEY 101
#  define F_KEY 102
#  define G_KEY 103
#  define H_KEY 104
#  define I_KEY 105
#  define J_KEY 106
#  define K_KEY 107
#  define L_KEY 108
#  define M_KEY 109
#  define N_KEY 110
#  define O_KEY 111
#  define P_KEY 112
#  define Q_KEY 113
#  define R_KEY 114
#  define S_KEY 115
#  define T_KEY 116
#  define U_KEY 117
#  define V_KEY 118
#  define W_KEY 119
#  define X_KEY 120
#  define Y_KEY 121
#  define Z_KEY 122

#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define RIGHT_KEY 65363
#  define LEFT_KEY 65361

#  define ESCAPE 65307
#  define ENTER 65293
#  define CLOSE 33

#  define N0_KEY 65438
#  define N1_KEY 65436
#  define N2_KEY 65433
#  define N3_KEY 65435
#  define N4_KEY 65430
#  define N5_KEY 65437
#  define N6_KEY 65432
#  define N7_KEY 65429
#  define N8_KEY 65431
#  define N9_KEY 65434

#  define UP0_KEY 48
#  define UP1_KEY 49
#  define UP2_KEY 50
#  define UP3_KEY 51
#  define UP4_KEY 52
#  define UP5_KEY 53
#  define UP6_KEY 54
#  define UP7_KEY 55
#  define UP8_KEY 56
#  define UP9_KEY 57
#  define DOT_KEY 46
#  define MINUS_KEY 45
#  define COMA_KEY 44

#  define UP0_KEYA 224
#  define UP1_KEYA 38
#  define UP2_KEYA 233
#  define UP3_KEYA 34
#  define UP4_KEYA 39
#  define UP5_KEYA 40
#  define UP6_KEYA 167
#  define UP7_KEYA 232
#  define UP8_KEYA 33
#  define UP9_KEYA 231
#  define DOT_KEYA 59

#  define MAX_DEFX 0
#  define MAX_DEFY 0

#  define DEC 20
#  define APPLE 0

# endif
#endif
