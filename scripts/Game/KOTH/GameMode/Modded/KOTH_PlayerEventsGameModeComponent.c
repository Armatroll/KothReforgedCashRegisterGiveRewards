modded class KOTH_PlayerEventsGameModeComponent : SCR_BaseGameModeComponent
{
	void HandleStealFromRegister(int playerId)
	{
		string playerUID = KOTH_Helper.GetPlayerUID(playerId);
		LogWorkbench("HandleStealFromRegister Player ID: " + playerId);

		KOTH_SCR_PlayerProfileComponent profileComp = KOTH_SCR_PlayerProfileComponent.Cast(m_playerManager.GetPlayerController(playerId).FindComponent(KOTH_SCR_PlayerProfileComponent));
		KOTH_PlayerProfileJson profile = m_kothBackendApi.m_CurrentProfileList.Get(playerUID);

		if (profileComp.GetHasFlushToilet())
			return;

		profile.AddXp(KOTH_Globals.BONUS_STEAL_FROM_REGISTER);
		profile.AddMoney(KOTH_Globals.BONUS_STEAL_FROM_REGISTER);

		m_sessionDataGameComp.AddSessionXpAndMoney(KOTH_Globals.BONUS_STEAL_FROM_REGISTER, KOTH_Globals.BONUS_STEAL_FROM_REGISTER, playerUID);
		m_kothBackendApi.DoRpcSyncProfileToPlayer(profile);

		// Show notification for player
		profileComp.StealFromRegister(KOTH_Globals.BONUS_STEAL_FROM_REGISTER.ToString());
	}
}