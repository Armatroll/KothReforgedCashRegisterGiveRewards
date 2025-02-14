modded class KOTH_SCR_PlayerProfileComponent : ScriptComponent
{
	protected bool m_hasStoleFromARegister = false;
	bool GetHasPlayerOpenedARegister()
	{
		return m_hasStoleFromARegister;
	}
	void StealFromRegister(string bonus)
	{
		if (m_hasStoleFromARegister)
			return;

		m_hasStoleFromARegister = true;
		Rpc(RpcDo_Notif_StealFromRegister, bonus);
	}
	[RplRpc(RplChannel.Reliable, RplRcver.Owner)]
	void RpcDo_Notif_StealFromRegister(string bonus)
	{
		SCR_HUDManagerComponent hudManager = SCR_HUDManagerComponent.GetHUDManager();
		if (hudManager) {
			KOTH_HUD kothHud = KOTH_HUD.Cast(hudManager.FindInfoDisplay(KOTH_HUD));
			if (kothHud) {
				kothHud.NotifStealFromRegister(bonus);
			}
		}
	}
	void ResetHasPlayerOpenedARegister()
	{
		m_hasStoleFromARegister = false;
	}
}
