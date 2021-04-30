from building import *
Import('rtconfig')

src   = []
cwd   = GetCurrentDir()

src += Glob('sensor_lsm6dsm.c')
src += Glob('driver/*.c')

# add lsm6dsm include path.
path  = [cwd, cwd + '/driver']

# add src and include to group.
group = DefineGroup('lsm6dsm', src, depend = ['PKG_USING_LSM6DSM'], CPPPATH = path)

Return('group')
