modded class KOTH_PlayerEventsGameModeComponent : SCR_BaseGameModeComponent
{
	KOTH_SCR_PlayerProfileComponent profileComp;
	KOTH_PlayerProfileJson profile;
	bool GetHasUserOpenedARegister()
	{
		if(profileComp == null)
		{
			return false;
		}
		return profileComp.GetHasPlayerOpenedARegister();
	}
	void ResetHasUserOpenedARegister()
	{
		if(profileComp == null)
		{
			return;
		}
		profileComp.ResetHasPlayerOpenedARegister();
	}
	void HandleStealFromRegister(int playerId)
	{
		string playerUID = KOTH_Helper.GetPlayerUID(playerId);
		LogWorkbench("HandleStealFromRegister Player ID: " + playerId);
		if(profileComp == null)
		{
			profileComp = KOTH_SCR_PlayerProfileComponent.Cast(m_playerManager.GetPlayerController(playerId).FindComponent(KOTH_SCR_PlayerProfileComponent));
		}
		if(profile == null)
		{
			profile = m_kothBackendApi.m_CurrentProfileList.Get(playerUID);
		}
		
		if (profileComp.GetHasPlayerOpenedARegister())
			return;

		profile.AddXp(KOTH_Globals.BONUS_STEAL_FROM_REGISTER);
		profile.AddMoney(KOTH_Globals.BONUS_STEAL_FROM_REGISTER);

		m_sessionDataGameComp.AddSessionXpAndMoney(KOTH_Globals.BONUS_STEAL_FROM_REGISTER, KOTH_Globals.BONUS_STEAL_FROM_REGISTER, playerUID);
		m_kothBackendApi.DoRpcSyncProfileToPlayer(profile);

		// Show notification for player
		profileComp.StealFromRegister(KOTH_Globals.BONUS_STEAL_FROM_REGISTER.ToString());
	}
}