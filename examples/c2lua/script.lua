-- lua example

ave = average(1.0, 2.0, 3.0, 4.0)

print(string.format("Lua: ave    = %g", ave))

if os.getenv("SMALL") == "YES" then
    width = 5
    height = 50
else
    width = 100
    height = 200
end

print(string.format("Lua: width  = %g", width))
print(string.format("Lua: height = %g", height))

