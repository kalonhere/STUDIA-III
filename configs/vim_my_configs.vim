map <C-n> :NERDTree

set nocompatible

call plug#begin()

" List your plugins here
Plug 'tpope/vim-sensible'
Plug 'sheerun/vim-polyglot'
Plug 'ghifarit53/tokyonight-vim'
Plug 'preservim/nerdtree'

call plug#end()
set termguicolors

let g:tokyonight_style = 'night' " available: night, storm
let g:tokyonight_enable_italic = 1

colorscheme tokyonight
