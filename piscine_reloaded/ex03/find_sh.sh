find . -name "*.sh" -type f | sed 's/.*\///g' | sed 's/\.sh$//'
