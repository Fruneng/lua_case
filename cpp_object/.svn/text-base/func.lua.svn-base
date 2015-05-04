
function test()

  local datetimes = {}
 
  for i=0, 10000 do
    datetimes[i] = datetime()
  end

  cbs_datetime = nil
end


test()
print("before lua gc memery:"..collectgarbage("count").."Kbtye")
collectgarbage("collect")
print("end lua gc memery:"..collectgarbage("count").."Kbyte")



local a = datetime()
print("a.classname() :"..a.classname())
local b = datetime()
local c = datetime()
--datetime_copy(b, c)

