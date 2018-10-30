/******************************************************
* Code for the handling of player groups. Written for *
* AwakeMUD Community Edition by Lucien Sadi. 06/03/17 *
******************************************************/

#ifndef _playergroups_h
#define _playergroups_h

// Privileges.
#define PRIV_ADMINISTRATOR                  0      // Can assign any priv they possess except Admin.
#define PRIV_AUDITOR                        1      // Can view the logs.
#define PRIV_ARCHITECT                      2      // Can edit the PGHQ blueprints.
#define PRIV_COCONSPIRATOR                  3      // In groups where membership is secret, allows viewing of roster.
#define PRIV_DRIVER                         4      // Can lock/unlock and drive any PG vehicle.
#define PRIV_LANDLORD                       5      // Can lease apts, relinquish apts, and add guests.
#define PRIV_LEADER                         6      // Can do anything.
#define PRIV_MANAGER                        7      // Can promote, demote, and outcast.
#define PRIV_MECHANIC                       8      // Can perform modifications to PG vehicles.
#define PRIV_PROCURER                       9      // Can purchase/sell PG vehicles.
#define PRIV_RECRUITER                      10     // Can invite members.
#define PRIV_TENANT                         11     // Can enter PG apartments.
#define PRIV_TREASURER                      12     // Can withdraw from the PG bank account.
#define PRIV_MAX                            13     /* Not an actual priv-- used for iteration over pgroup_privileges[].
                                                      Must always be equal to total number of privileges, not including priv_none of course. */
#define PRIV_NONE                           10000  // No privilege required.

// Playergroup settings.
#define PGROUP_FOUNDED                      0 // Set by PGROUP FOUND, indicates that group is fully founded/active.
#define PGROUP_DISABLED                     1 // Set by PGROUP DISBAND.
#define PGROUP_SECRETSQUIRREL               2 // TODO: Membership is secret and requires PRIV_COCONSPIRATOR to view.
#define PGROUP_CLONE                        3 // This group is a clone used for pgedit.

// Edit modes.
#define PGEDIT_CONFIRM_EDIT                 0
#define PGEDIT_MAIN_MENU                    1
#define PGEDIT_CHANGE_NAME                  2
#define PGEDIT_CHANGE_ALIAS                 3
#define PGEDIT_CHANGE_TAG                   4
#define PGEDIT_CONFIRM_SAVE                 5

// Configurables.
#define NUM_MEMBERS_NEEDED_TO_FOUND         2 // TODO: Should be 3, but decreased for testing purposes.
#define COST_TO_FOUND_GROUP                 100000 // Nuyen that must be paid by the founding player in order to make a group official.

// Helper functions.
#define GET_PGROUP_DATA(ch)                 (ch)->pgroup
#define GET_PGROUP(ch)                      (ch)->pgroup->pgroup

// Maximums.
#define MAX_PGROUP_RANK                     10
#define MAX_PGROUP_NAME_LENGTH              80  // If you change this, update your SQL tables too. SQL field length should be 2x+1 this (or greater).
#define MAX_PGROUP_ALIAS_LENGTH             20  // If you change this, update your SQL tables too. SQL field length should be 2x+1 this (or greater).
#define MAX_PGROUP_LOG_LENGTH               256 // If you change this, update your SQL tables too. SQL field length should be 2x+1 this (or greater).
#define MAX_PGROUP_LOG_READBACK             7 // The maximum number of days into the past players can view group logs.

// Tag maximums: Only update tag-without-color, and update your SQL tables too. SQL field length should be MAX_PGROUP_TAG_LENGTH + 1 (or greater).
#define MAX_PGROUP_TAG_LENGTH_WITHOUT_COLOR 7
#define MAX_PGROUP_TAG_LENGTH               (MAX_PGROUP_TAG_LENGTH_WITHOUT_COLOR * 3 + 2) // Accounts for color codes before each letter as well as a ^n at the end.


// Function prototypes.
long get_new_pgroup_idnum();
void display_pgroup_help(struct char_data *ch);
void pgedit_parse(struct descriptor_data *d, const char *arg);
void pgedit_disp_menu(struct descriptor_data *d);
bool has_valid_pocket_secretary(struct char_data *ch);

// Command prototypes.
void do_pgroup_abdicate(struct char_data *ch, char *argument);
void do_pgroup_balance(struct char_data *ch, char *argument);
void do_pgroup_buy(struct char_data *ch, char *argument);
void do_pgroup_contest(struct char_data *ch, char *argument);
void do_pgroup_create(struct char_data *ch, char *argument);
void do_pgroup_donate(struct char_data *ch, char *argument);
void do_pgroup_design(struct char_data *ch, char *argument);
void do_pgroup_disband(struct char_data *ch, char *argument);
void do_pgroup_edit(struct char_data *ch, char *argument);
void do_pgroup_found(struct char_data *ch, char *argument);
void do_pgroup_grant(struct char_data *ch, char *argument);
void do_pgroup_help(struct char_data *ch, char *argument);
void do_pgroup_invitations(struct char_data *ch, char *argument);
void do_pgroup_invite(struct char_data *ch, char *argument);
void do_pgroup_lease(struct char_data *ch, char *argument);
void do_pgroup_logs(struct char_data *ch, char *argument);
void do_pgroup_note(struct char_data *ch, char *argument);
void do_pgroup_outcast(struct char_data *ch, char *argument);
void do_pgroup_promote(struct char_data *ch, char *argument);
void do_pgroup_privileges(struct char_data *ch, char *argument);
void do_pgroup_resign(struct char_data *ch, char *argument);
void do_pgroup_revoke(struct char_data *ch, char *argument);
void do_pgroup_roster(struct char_data *ch, char *argument);
void do_pgroup_status(struct char_data *ch, char *argument);
void do_pgroup_transfer(struct char_data *ch, char *argument);
void do_pgroup_vote(struct char_data *ch, char *argument);
void do_pgroup_withdraw(struct char_data *ch, char *argument);

#endif
