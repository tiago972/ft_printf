CC = clang 
CFLAGS = -Wall -Wextra -Werror -I $(INCL)
NAME = libftprintf.a
OBJDIR = objs
SRCDIR = ./srcs
SRC = ft_printf.c \
	  display.c \
	 numbers.c \
	 parse.c \
	 tools.c
INCL = ./includes
LIBCREATOR = $(addprefix $(LIBDIR)/, $(LIB))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
DEBUG = debug
CLFLAGS_DEBUG = -g3 -I $(INCL)
DEBUG_FOLDER = debug
DEBUG_SRC = $(DEBUG_FOLDER)/main.c
DEBUG_OBJS_FOLDER = objs
DEBUG_OBJ = $(addprefix $(DEBUG_FOLDER)/$(OBJS_DEBUG_FOLDER), $(addsuffix .o, $(basename $(DEBUG_SRC))))
include libft/Makefile_lib

all: $(NAME)

$(NAME): $(OBJ) $(NAME_LIB) 
	ar rc $(NAME) $(OBJ_LIB) $<
	@ranlib $(NAME)
	@echo "\n\033[38;5;4;1;4m$(NAME)\033[0m compiled successfully\n" 

$(OBJDIR)/%.o : $(SRCDIR)/%.c  
	@mkdir -p $(OBJDIR)
	@echo "\033[38;5;82m$@\033[0m has been created" 
	@$(CC) -o $@ -c $? $(CFLAGS)

clean: 
	@rm -rf $(OBJDIR)
	@echo "\033[38;5;208m$(OBJDIR)\033[0m has been deleted" 

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;208m$(NAME)\033[0m has been deleted" 

re: fclean all

fclean_all: fclean_lib fclean

re_all: fclean_lib re

$(DEBUG): $(DEBUG_OBJ) $(NAME)
	@$(CC) $(CLFLAGS) -o $@ $(DEBUG_OBJ) -L. -lftprintf
	@echo "\n\033[38;1;25m READY to debug man\033[0m\n"

$(DEBUG_OBJ): $(DEBUG_SRC)
	@mkdir -p $(DEBUG_FOLDER)/$(DEBUG_OBJS_FOLDER)
	$(CC) $(CLAGS_DEBUG) -o $@ -c $<

clean_deb:
	@rm -rf $(DEBUG_OBJ)
fclean_deb: clean_deb
	@rm -rf $(DEBUG)

re_debug: fclean_deb $(DEBUG)

.PHONY: clean fclean all
