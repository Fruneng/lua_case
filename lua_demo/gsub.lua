x = string.gsub("hello world", "(%w+)", "%1 %1")
--> x="hello hello world world"

x = string.gsub("hello world", "%w+", "%0 %0", 1)
--> x="hello hello world"

x = string.gsub("hello world from Lua", "(%w+)%s*(%w+)", "%2 %1")
--> x="world hello Lua from"

x = string.gsub("home = $HOME, user = $USER", "%$(%w+)", os.getenv)
--> x="home = /home/roberto, user = roberto"

x = string.gsub("4+5 = $return 4+5$", "%$(.-)%$", function (s)
     return loadstring(s)()
   end)
--> x="4+5 = 9"

local t = {name="lua", version="5.1"}
x = string.gsub("$name%-$version%.tar.gz", "%$(%w+)%%", t)

local text = 
"123456\r\n789\r\n123"
x = string.gsub(text, "(.-)(?:\r\n|\n)", function (s)
  print("line:"..s)
end)
