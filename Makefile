##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC = 	src/main.c \
		src/buttons_functions/change_fps.c \
		src/buttons_functions/change_res.c \
		src/buttons_functions/change_scene.c \
		src/buttons_functions/change_volume.c \
		src/buttons_functions/empty.c \
		src/buttons_functions/exit.c \
		src/buttons_functions/menu.c \
		src/buttons_functions/resume.c \
		src/buttons_functions/select_turret.c \
		src/buttons_functions/turret.c \
		src/draw/draw_first_level.c \
		src/draw/draw_how_to_play.c \
		src/draw/draw_menu.c \
		src/draw/draw_selection.c \
		src/draw/draw_settings.c \
		src/enemy/animation_enemy.c \
		src/enemy/init_enemy.c \
		src/enemy/move_enemy.c \
		src/enemy/damage_enemy.c \
		src/events/event_first_level.c \
		src/events/event_how_to_play.c \
		src/events/event_level_button.c \
		src/events/event_menu.c \
		src/events/event_selection.c \
		src/events/event_settings.c \
		src/free/free_game.c \
		src/free/free_in_game.c \
		src/free/free_scene.c \
		src/game/game_loop.c \
		src/game/init_in_game.c \
		src/interface/button.c \
		src/interface/text.c \
		src/map/display_map.c \
		src/map/display_map2.c \
		src/map/map.c \
		src/map/map2.c \
		src/map/path/get_path.c \
		src/map/path/handle_border.c \
		src/map/path/handle_corner.c \
		src/map/path/handle_inside.c \
		src/player/init_player.c \
		src/scenes/scene_first_level.c \
		src/scenes/scene_second_level.c \
		src/scenes/scene_third_level.c \
		src/scenes/scene_forth_level.c \
		src/scenes/scene_how_to_play.c \
		src/scenes/scene_menu.c \
		src/scenes/scene_selection.c \
		src/scenes/scene_settings.c \
		src/scenes/util/create_sett_buttons.c \
		src/scenes/util/util_level.c \
		src/scenes/util/util_level2.c \
		src/sound/sound.c \
		src/spawner/init_spawner.c \
		src/spawner/new_wave.c \
		src/spawner/time_spawner.c \
		src/turrets/change_turret_price_text.c \
		src/turrets/display_turret.c \
		src/turrets/get_turret_sprite_index.c \
		src/turrets/range_turret.c \
		src/turrets/init_freeze.c \
		src/turrets/init_medium.c \
		src/turrets/init_heavy.c \
		src/turrets/init_sniper.c \
		src/turrets/upgrade_turret.c \
		src/turrets/price_turret.c \
		src/update/update_first_scene.c \
		src/update/update_how_to_play.c \
		src/update/update_level_button.c \
		src/update/update_menu_scene.c \
		src/update/update_selection.c \
		src/update/update_settings.c \
		src/util/file.c \
		src/util/nb_to_string.c \
		src/util/random.c \

OBJ = $(SRC:.c=.o)

NAME = my_defender

CC = gcc

RM = rm

CFLAGS = -W -Wall -Wextra -g3

CPPFLAGS = -I./include

LDFLAGS = -L./lib -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

all: $(NAME)

libbuild:
	make all -C ./lib/my/

$(NAME): libbuild $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -s -C ./lib/my/
	$(RM) -f $(OBJ)

fclean:	clean
	make fclean -s -C ./lib/my/
	$(RM) -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re libbuild