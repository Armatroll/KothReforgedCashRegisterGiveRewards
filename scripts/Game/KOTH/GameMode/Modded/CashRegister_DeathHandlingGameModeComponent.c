modded class KOTH_DeathHandlingGameModeComponent : SCR_BaseGameModeComponent
{
	override void CleanupPlayer(KOTH_DeathEvent deathEvent)
	{
		Print("CLEANUP START");
		deathEvent.playerProfileComp.ResetHasPlayerOpenedARegister();
		// call overrider function
		super.CleanupPlayer(deathEvent);
		Print("CLEANUP ENDED");
	}
	
}