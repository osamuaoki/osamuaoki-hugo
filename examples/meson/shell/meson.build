project('foo', version : '0.1')
# run in setup
date = find_program('date')
sed = find_program('sed')
sh = find_program('sh')
cat = find_program('cat')

datex = 's/@timestamp@/' + run_command(date, '--iso=sec', '-u').stdout().strip() + '/'
versionx = 's/@version@/' + meson.project_version() + '/'
hellox = 's/@msg@/date=@timestamp@ version=@version@ -- Hello World!/'

# run in compile
date1 = custom_target('date1',
  capture : true,
  output : 'date1',
  command : [ date, '--iso=sec', '-u' ])

date2 = custom_target('date2',
  input : date1,
  capture : true,
  output : 'date2',
  command : [ sed, '-e', 's/^/echo "date=/', '-e', 's/$/"/', '@INPUT@' ])

foo1 = custom_target('foo1',
  input : 'foo0',
  capture : true,
  output : 'foo1',
  command : [ sed, '-e', hellox , '-e', datex, '-e', versionx, '@INPUT@'])

sh1 = custom_target('sh1',
  input : '/etc/motd',
  capture : true,
  output : 'sh1',
  command : [ sh, '-c', 'cat /etc/motd | grep -e GNU | sed -e \'s/^/echo "motd=/\' -e \'s/$/"/\' '])

foo = custom_target('default',
  input : [foo1, date2, sh1],
  build_by_default: true,
  capture : true,
  output : 'foo',
  command : [ cat, '@INPUT@'])

