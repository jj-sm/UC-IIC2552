let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Local/uc/IIC2552/UC-IIC2552
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +23 problems/0603/B/sol.cpp
badd +2 problems/0603/B/input.txt
badd +4 problems/0603/B/solution.txt
badd +55 term://~/Local/uc/IIC2552/UC-IIC2552//80005:/bin/zsh
argglobal
%argdel
edit problems/0603/B/sol.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 117 + 117) / 235)
exe '2resize ' . ((&lines * 27 + 28) / 57)
exe 'vert 2resize ' . ((&columns * 117 + 117) / 235)
exe '3resize ' . ((&lines * 27 + 28) / 57)
exe 'vert 3resize ' . ((&columns * 117 + 117) / 235)
argglobal
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 23 - ((22 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 23
normal! 016|
wincmd w
argglobal
if bufexists(fnamemodify("problems/0603/B/solution.txt", ":p")) | buffer problems/0603/B/solution.txt | else | edit problems/0603/B/solution.txt | endif
if &buftype ==# 'terminal'
  silent file problems/0603/B/solution.txt
endif
balt problems/0603/B/input.txt
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 4 - ((3 * winheight(0) + 13) / 27)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 4
normal! 04|
wincmd w
argglobal
if bufexists(fnamemodify("term://~/Local/uc/IIC2552/UC-IIC2552//80005:/bin/zsh", ":p")) | buffer term://~/Local/uc/IIC2552/UC-IIC2552//80005:/bin/zsh | else | edit term://~/Local/uc/IIC2552/UC-IIC2552//80005:/bin/zsh | endif
if &buftype ==# 'terminal'
  silent file term://~/Local/uc/IIC2552/UC-IIC2552//80005:/bin/zsh
endif
balt problems/0603/B/input.txt
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
let s:l = 27 - ((26 * winheight(0) + 13) / 27)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 27
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 117 + 117) / 235)
exe '2resize ' . ((&lines * 27 + 28) / 57)
exe 'vert 2resize ' . ((&columns * 117 + 117) / 235)
exe '3resize ' . ((&lines * 27 + 28) / 57)
exe 'vert 3resize ' . ((&columns * 117 + 117) / 235)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
