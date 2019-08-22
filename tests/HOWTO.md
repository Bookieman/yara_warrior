## How to create a yara module

# create <module_name>.c inside libyara/modules

# create your module

# add "MODULE(<module_name>) in the libyara/modules/module_list

# add "MODULES += modules/<module_name>.c" and "MODULES += modules/<dependance_name>.c" to the Makefile.am

