#!/bin/bash
rm -r "Push-Swap-Tester/"
rm -r "checker_linux"
rm -r "push_swap_tester/"
rm -r "push_swap_visualizer-master/"
make fclean >/dev/null 2>&1 || true
rm -r "$0"
