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
DEBUG = test
CLFLAGS_DEBUG = -g3 -I $(INCL)
DEBUG_FOLDER = ./debug
DEBUG_SRC = $(addprefix $(DEBUG_FOLDER)/, main.c)
DEBUG_OBJS_FOLDER = $(addprefix $(DEBUG_FOLDER)/, objs)
DEBUG_OBJ = $(addprefix $(DEBUG_OBJS_FOLDER)/, $(addsuffix .o, $(basename $(notdir $(DEBUG_SRC)))))
include libft/Makefile_lib

all: $(NAME)
	echo $(DEBUG_OBJS_FOLDER)/%.o:
$(NAME): $(OBJ) $(OBJ_LIB)
	@ar rc $(NAME) $^ 
	@ranlib $(NAME)
	@echo "\n\033[38;5;4;1;4m$(NAME)\033[0m compiled successfully\n" 

$(OBJDIR)/%.o : $(SRCDIR)/%.c  
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< $(CFLAGS) 
	@echo "\033[38;5;82m$@\033[0m has been created" 

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
	@$(CC) $(CLFLAGS_DEBUG) -o $@ $(DEBUG_OBJ) -L. -lftprintf
	@echo "\n\033[38;5;208m READY to debug man\033[0m\n"

$(DEBUG_OBJS_FOLDER)/%.o: $(DEBUG_SRC)
	@mkdir -p $(DEBUG_OBJS_FOLDER)
	@$(CC) $(CLFLAGS_DEBUG) -o $@ -c $<

clean_deb:
	@rm -f $(DEBUG_OBJ)

fclean_deb: clean_deb
	@rm -f $(DEBUG)

re_debug: fclean_deb $(DEBUG)

.PHONY: clean fclean all clean_deb fclean_deb re_debug
