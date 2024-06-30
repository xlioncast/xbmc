/*
 *  Copyright (C) 2012-2023 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "pvr/channels/PVRChannelGroup.h"

namespace PVR
{

class CPVRChannelGroupFromUser : public CPVRChannelGroup
{
public:
  /*!
   * @brief Create a new channel group instance.
   * @param path The channel group path.
   * @param allChannelsGroup The channel group containing all TV or radio channels.
   */
  CPVRChannelGroupFromUser(const CPVRChannelsPath& path,
                           const std::shared_ptr<const CPVRChannelGroup>& allChannelsGroup)
    : CPVRChannelGroup(path, allChannelsGroup)
  {
  }

  /*!
   * @brief Get the group's origin.
   * @return The origin.
   */
  Origin GetOrigin() const override { return Origin::USER; }

  /*!
   * @brief Return the type of this group.
   */
  int GroupType() const override { return PVR_GROUP_TYPE_USER; }

  /*!
   * @brief Check whether this group could be deleted by the user.
   * @return True if the group could be deleted, false otherwise.
   */
  bool SupportsDelete() const override { return true; }

  /*!
   * @brief Check whether members could be added to this group by the user.
   * @return True if members could be added, false otherwise.
   */
  bool SupportsMemberAdd() const override { return true; }

  /*!
   * @brief Check whether members could be removed from this group by the user.
   * @return True if members could be removed, false otherwise.
   */
  bool SupportsMemberRemove() const override { return true; }

  /*!
   * @brief Check whether this group is owner of the channel instances it contains.
   * @return True if owner, false otherwise.
   */
  bool IsChannelsOwner() const override { return false; }

  /*!
   * @brief Check whether this group should be ignored, e.g. not presented to the user and API.
   * @param allChannelGroups All available channel groups.
   * @return True if to be ignored, false otherwise.
   */
  bool ShouldBeIgnored(
      const std::vector<std::shared_ptr<CPVRChannelGroup>>& allChannelGroups) const override
  {
    // User-created groups shall always be present.
    return false;
  }

  /*!
   * @brief Update data with channel group members from the given clients, sync with local data.
   * @param clients The clients to fetch data from. Leave empty to fetch data from all created clients.
   * @return True on success, false otherwise.
   */
  bool UpdateFromClients(const std::vector<std::shared_ptr<CPVRClient>>& clients) override
  {
    return true; // Nothing to update from any client for locally managed groups.
  }
};
} // namespace PVR
