Core = cPluginManager:Get():GetPluginHandle("Core")

function SendMessage(a_Player, a_Message)
	if (Core ~= nil and Core.TryLoadLock()) then
		Core:Call("SendMessage", a_Player, a_Message)
		Core.ReleaseLoadLock()
	end
end

function SendMessageSuccess(a_Player, a_Message)
	if (Core ~= nil and Core.TryLoadLock()) then
		Core:Call("SendMessageSuccess", a_Player, a_Message)
		Core.ReleaseLoadLock()
	end
end

function SendMessageFailure(a_Player, a_Message)
	if (Core ~= nil and Core.TryLoadLock) then
		Core:Call("SendMessageFailure", a_Player, a_Message)
		Core.ReleaseLoadLock()
	end
end
