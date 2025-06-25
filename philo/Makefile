NAME            = philosopher

SOURCES         = main.c philo.c routine.c init.c utils.c

OBJECTS         = $(SOURCES:.c=.o)

CC              = cc
CFLAGS          = -Wall -Wextra -Werror
RM              = rm -rf

GREEN           = \033[1;32m
RED             = \033[1;31m
YELLOW          = \033[1;33m
BLUE            = \033[1;34m
CYAN            = \033[1;36m
RESET           = \033[0m
PURPLE          = \033[1;35m

all: banner $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $^ -o $(NAME) >/dev/null 2>&1
	@echo "$(GREEN)✔ $(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -Iincludes -c $< -o $@ >/dev/null 2>&1

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJECTS) >/dev/null 2>&1

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME) >/dev/null 2>&1

re: fclean all

banner:
	@echo "$(YELLOW)                                           ...............                                          "
	@echo "$(YELLOW)                                     .......             ..                                         "
	@echo "$(YELLOW)                                    ..                    ...                                        "
	@echo "$(YELLOW)                                   ..             ....      :.                                      "
	@echo "$(YELLOW)                                   ..          ...........   .:                                     "
	@echo "$(YELLOW)                                 ...          ..          :.  :                                     "
	@echo "$(YELLOW)                                ..            :            :.:.                                    "
	@echo "$(YELLOW)                                ..           ..            ..                                       "
	@echo "$(YELLOW)                                 ..    ......              ..                                       "
	@echo "$(YELLOW)                                 .    .. ..                ..                                       "
	@echo "$(YELLOW)                                ..    ..  ..               ..                                       "
	@echo "$(YELLOW)                                .      ..  ..              .::.                                    "
	@echo "$(YELLOW)                                ...    ..   ..       ....  .. :.                                   "
	@echo "$(YELLOW)                                 .:     :     ......     ...  :.                                   "
	@echo "$(YELLOW)                                 ..    ..           .....    .:                                    "
	@echo "$(YELLOW)                                  ..    :.                   :.                                   "
	@echo "$(YELLOW)                                   ........                  -                                    "
	@echo "$(YELLOW)                                         .:                  -                                    "
	@echo "$(YELLOW)                                           .::.             ::                                   "
	@echo "$(YELLOW)                                           .. .....:.:.::....                                    "
	@echo "$(YELLOW)                                           ..   .      .: :::.:......                             "
	@echo "$(YELLOW)                                     .......            -:    ::    =                             "
	@echo "$(YELLOW)                              .::....                 .-.    ::    .=:                          "
	@echo "$(YELLOW)                            :.                      .-.     ::     :: :-                         "
	@echo "$(YELLOW)                           :.                     ::.      -.      =   .=                        "
	@echo "$(YELLOW)                           :.                  .:.       .-.      .-   .-                        "
	@echo "$(YELLOW)                            :.              ..:.        ::        =   .=                         "
	@echo "$(YELLOW)                             :.           ::.         .-.        -:  .=                          "
	@echo "$(YELLOW)                              .:      .-:.          .-.         .=  =-                            "
	@echo "$(YELLOW)                                .:.:..            .-.     :.    =.--                             "
	@echo "$(YELLOW)                                :.              .:.      -:    ==.                               "
	@echo "$(YELLOW)                                .:.             .       -.    =.                                 "
	@echo "$(YELLOW)                                  .:..                .-     =--                                 "
	@echo "$(YELLOW)                                   .:.:-..           -=....:=  -:                                "
	@echo "$(YELLOW)                                   .:     .:-===--==-          -:                                "
	@echo "$(YELLOW)                                    ::                        --                                  "
	@echo "$(YELLOW)                                      .-::::::::::::::::::--=:                                    "
	@echo "$(YELLOW)                                       =                    +                                     "
	@echo "$(YELLOW)                                       =.                  .+                                     "
	@echo "$(YELLOW)                                 :-.............................:==                              "
	@echo "$(CYAN)                                 -.\"I think, therefore I compile.\".+                              "
	@echo "$(YELLOW)                                  .:::::::::::::::::::::::::::::--                               "
	@echo "$(RESET)"